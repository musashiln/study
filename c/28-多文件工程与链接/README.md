# 28 多文件工程与链接

## 学习目标

理解预处理、编译、汇编、链接，能够组织 h、c、tests 多文件项目。

## 1. 目录和接口

~~~text
include/math_utils.h
src/math_utils.c
src/main.c
tests/main.c
~~~

头文件放声明并使用保护宏：

~~~c
#ifndef MATH_UTILS_H
#define MATH_UTILS_H
int add(int a, int b);
#endif
~~~

实现放 c 文件：

~~~c
#include "math_utils.h"
int add(int a, int b) { return a + b; }
~~~

## 2. 编译流程

~~~text
预处理 .c -> .i
编译 .i -> .s
汇编 .s -> .o
链接 多个 .o -> exe
~~~

操作命令：

~~~powershell
gcc -E src/main.c -o .build/main.i
gcc -S src/main.c -o .build/main.s
gcc -c src/math_utils.c -I include -o .build/math_utils.o
gcc .build/math_utils.o .build/main.o -o .build/app.exe
~~~

## 3. static、extern 和链接错误

extern 声明其他文件定义的变量；static 隐藏文件内部函数和变量。编译成功但链接失败，通常是声明存在而实现缺失，或符号被重复定义。

## 4. Makefile

先理解命令，再写 Makefile。目标包括 all、debug、clean。每个源文件先编译成目标文件，只有改变的文件才需要重新编译。

## 操作步骤

1. 编译本章示例。
2. 删除一个函数实现，观察 undefined reference。
3. 重复定义函数，观察 multiple definition。
4. 把顺序表拆成 list.h、list.c、test_list.c。
5. 写 Makefile 或对应的 VS Code task。

## 练习

1. 拆分动态数组模块。
2. 用 static 隐藏辅助函数。
3. 为模块设计 init、destroy 和错误码。
4. 写 all、debug、clean 三个目标。

## 完成标准

能解释编译成功但链接失败的原因，并能独立创建 h 加 c 加 tests 模块。
