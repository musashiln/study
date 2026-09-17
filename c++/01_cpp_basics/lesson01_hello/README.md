# 第 01 课 - Hello, C++

## 学习目标

- 认识 C++ 程序的入口
- 在终端输出文本
- 编译并运行一个源文件
- 理解 `#include`、`main`、语句和 `return` 的作用

## 练习

修改 `main.cpp`，使程序分三行输出以下内容：

1. 你的姓名
2. 你学习 ROS 2 和嵌入式开发的目标
3. 想对未来的自己说的一句话

编译并运行程序。若遇到报错，请把命令、完整报错、原因和解决方法记录到 `notes/` 目录。

## Windows 中文乱码

源代码文件使用 UTF-8 编码，而 Windows 终端若仍使用 GBK 代码页，输出中文会显示为乱码。每次打开新的 PowerShell 终端后，先执行：

```powershell
chcp 65001
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
$OutputEncoding = [System.Text.Encoding]::UTF8
```

再运行程序：

```powershell
.\build\lesson01.exe
```

这会把当前终端切换为 UTF-8；只对当前终端窗口生效。
