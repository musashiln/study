# 23-交叉编译调试工程化

## 核心笔记
掌握 Makefile、编译选项、头文件依赖、map 文件、断点、观察寄存器和栈回溯。交叉编译器通常形如 arm-none-eabi-gcc；下载器和调试器常用 GDB/OpenOCD。每次提交保留可复现的构建命令。

## 跟练提示
先手敲 src/main.c，再完成 exercises.md。把与具体芯片有关的内容写入 notes.md。
