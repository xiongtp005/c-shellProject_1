# LinuxShellProject 开发文档 

## 项目简介 LinuxShellProject 是一个用 C++ 实现的简单 Linux Shell 程序。该项目支持基本的命令输入与执行功能，并能够运行简单的 Shell 脚本。 

## 项目结构 

项目结构描述：

LinuxShellProject/
├── CMakeLists.txt # CMake 构建配置文件
├── src/ # 源代码目录
│ └── myshell.cpp # 主程序文件
└── presentation/ # 项目答辩相关文件
|  └── video.mp4 # 答辩视频 
└── readme.md 

## 需求分析

实现一个能够读取并执行用户命令的 Shell 程序。

支持运行简单的 Shell 脚本文件。

使用 C++ 标准库及 Linux 系统调用来实现。

## 设计概述

项目设计包括以下主要模块：

1.命令解析与执行模块：

解析用户输入的命令。

使用 fork() 和 execvp() 来创建子进程并执行命令。

2.脚本执行模块：

读取并逐行执行 Shell 脚本文件。

##核心功能代码

命令解析与执行

void execute_command(const std::string& command) { // 解析命令并执行 } 

脚本执行

void execute_script(const std::string& filename) { // 读取脚本文件并逐行执行命令 } 

## 遇到的难点与解决方案

1.命令解析：最初尝试使用 std::stringstream 进行命令解析，但发现处理空格分隔的命令和参数较为复杂，最终使用了手动拆分字符串的方法。

2.子进程管理：确保父进程能够正确等待子进程结束，避免产生僵尸进程。

## 开发成员
熊天平
