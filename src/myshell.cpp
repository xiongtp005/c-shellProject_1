#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(const std::string& command) {
    std::vector<std::string> args;
    std::string arg;
    for (size_t i = 0; i < command.length(); ++i) {
        if (command[i] == ' ') {
            if (!arg.empty()) {
                args.push_back(arg);
                arg.clear();
            }
        } else {
            arg += command[i];
        }
    }
    if (!arg.empty()) {
        args.push_back(arg);
    }

    if (args.empty()) return;

    std::vector<char*> argv;
    for (auto& s : args) {
        argv.push_back(&s[0]);
    }
    argv.push_back(nullptr);

    pid_t pid = fork();
    if (pid == 0) {
        execvp(argv[0], argv.data());
        std::cerr << "Error: Command not found" << std::endl;
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        waitpid(pid, nullptr, 0);
    } else {
        std::cerr << "Error: Fork failed" << std::endl;
    }
}

void execute_script(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open script file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            execute_command(line);
        }
    }
}

int main() {
    std::string input;
    while (true) {
        std::cout << "shell> ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        if (input.substr(0, 4) == "run ") {
            std::string filename = input.substr(4);
            execute_script(filename);
        } else {
            execute_command(input);
        }
    }
    return 0;
}
