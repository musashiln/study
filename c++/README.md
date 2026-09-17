# C++ 学习工作区

这个工作区记录从 C++ 基础到 ROS 2 与嵌入式开发的完整学习过程。

## 目录结构

```text
.
|-- 00_setup/                 开发环境与编译器基础
|-- 01_cpp_basics/            语法、流程控制、函数和基础输入输出
|-- 02_data_and_memory/       数组、字符串、引用、指针和内存
|-- 03_object_oriented/       类、继承、多态和 RAII
|-- 04_modern_cpp/            STL、智能指针、Lambda 和现代 C++
|-- 05_engineering/           CMake、测试、调试、Git 和工程结构
|-- 06_linux_and_concurrency/ Linux 工具、进程、线程和同步
|-- 07_ros2/                  ROS 2 节点、话题、服务、参数和 TF2
|-- 08_embedded/              MCU、外设、通信协议和 RTOS
|-- projects/                 跨阶段综合练习项目
|-- notes/                    个人笔记和错误记录
`-- PROGRESS.md               学习进度清单
```

每一课使用独立目录，目录中包含 `README.md` 和源代码。

在工作区根目录编译单节课：

```powershell
New-Item -ItemType Directory -Force build
g++ -std=c++17 -Wall -Wextra -Wpedantic .\01_cpp_basics\lesson01_hello\main.cpp -o .\build\lesson01.exe
.\build\lesson01.exe
```

编译生成的可执行文件和构建产物应放入 `build/`，不要与源文件混放。
