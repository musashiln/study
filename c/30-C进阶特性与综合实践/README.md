# 30 C 进阶特性与综合实践

## 学习目标

综合使用函数指针、回调、指定初始化、柔性数组、restrict、原子操作、字节序、多文件、错误处理和测试。

## 1. 函数指针和回调

~~~c
typedef int (*CompareFn)(int, int);
void sort(int *data, size_t n, CompareFn compare);
~~~

函数指针适合可配置排序、事件回调和驱动接口。调用前检查是否为空且签名匹配。

## 2. 指定初始化

~~~c
struct Config config = {
    .baudrate = 115200,
    .data_bits = 8,
    .enabled = 1
};
~~~

它能减少结构体字段顺序错误。

## 3. 柔性数组

~~~c
struct Packet {
    size_t length;
    unsigned char data[];
};
~~~

分配 sizeof(struct Packet) 加 length 的空间，释放整个结构体即可。计算大小时要检查溢出。

## 4. restrict 和原子操作

restrict 是给编译器的别名承诺，只有确实没有别名访问时才使用。C11 stdatomic.h 提供 atomic_int、atomic_load、atomic_store。原子操作不等于完整锁。

## 5. 字节序

不要直接把结构体内存写入网络或文件。显式拆分字节，明确协议规定的顺序。

## 综合项目：多文件通讯录

建议目录：

~~~text
include/contact.h
include/storage.h
src/contact.c
src/storage.c
src/main.c
tests/test_contact.c
Makefile
~~~

功能：添加、查找、删除、排序、保存、加载、错误输入处理、AddressSanitizer、单元测试和回归测试。

## 操作步骤

1. 先写头文件接口，不写实现。
2. 写内存所有权和错误码约定。
3. 单独测试添加、查找、删除。
4. 加入文件保存和加载。
5. 用 qsort 和函数指针支持不同排序。
6. 用 AddressSanitizer 和完整警告编译。
7. 用 GDB 调试一个故意错误。
8. 写 README 记录所有命令。

## 练习

1. 用函数指针实现升序和降序。
2. 用指定初始化创建配置。
3. 写字节序检测程序。
4. 把 17-综合项目拆成多文件并补全测试。

## 完成标准

能独立组织多文件 C 项目，明确模块边界、内存所有权、错误处理和测试方法，并能迁移到 408 和嵌入式项目。
