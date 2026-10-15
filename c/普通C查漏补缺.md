# 普通 C 查漏补缺清单

现有 01~17 已覆盖 C 语言入门主线。下面内容建议作为基础教程的补充，不必一次学完，但在进入大型项目、408 或嵌入式前应逐步补齐。

## A. 语言规则与可移植性

- [ ] 声明、定义、初始化的区别
- [ ] 作用域、存储期、链接属性：`auto`、`static`、`extern`
- [ ] 头文件、源文件、翻译单元、头文件保护宏
- [ ] 整数提升、通常算术转换、隐式窄化转换
- [ ] 有符号溢出、无符号回绕、移位边界
- [ ] 未定义行为、未指定行为、实现定义行为
- [ ] 字节序、对齐、填充和 `sizeof` 的平台差异
- [ ] `const`、`volatile`、`restrict` 的区别

## B. 指针和内存安全

- [ ] `const int *`、`int *const`、`const int *const`
- [ ] `void *` 与显式类型转换
- [ ] 指针运算和指针比较的合法范围
- [ ] 对象生命周期、悬空指针、重复释放
- [ ] 所有权约定：谁申请、谁使用、谁释放
- [ ] `realloc` 的安全写法
- [ ] 栈溢出、缓冲区越界、内存泄漏、Use-after-free
- [ ] 用 AddressSanitizer 或 Valgrind 定位内存错误

## C. 标准库补充

- [ ] `<stdint.h>`：`int8_t`、`uint32_t`
- [ ] `<stdbool.h>`：`bool`、`true`、`false`
- [ ] `<stddef.h>`：`size_t`、`ptrdiff_t`
- [ ] `<limits.h>`、`<float.h>`：类型边界
- [ ] `<assert.h>`：断言
- [ ] `<errno.h>`、`perror`、错误码设计
- [ ] `<ctype.h>`：字符分类
- [ ] `<stdlib.h>`：转换、排序、查找、随机数
- [ ] `<string.h>`：安全复制、比较和内存函数
- [ ] `qsort`、`bsearch` 和函数指针

## D. 多文件和工程化

- [ ] `.h` 放接口，`.c` 放实现
- [ ] `static` 限制文件内可见性
- [ ] `extern` 和全局变量的正确使用
- [ ] 多个 `.c` 文件分别编译、最后链接
- [ ] Makefile 基础、增量编译和依赖关系
- [ ] Debug/Release 编译选项
- [ ] map 文件、目标文件、静态库 `.a`
- [ ] 命令行编译和 VS Code 任务配置的对应关系

## E. 调试、测试和代码质量

- [ ] 断点、单步、步入、步过、查看调用栈
- [ ] 编译警告全部理解，不盲目关闭
- [ ] 正常输入、边界输入、错误输入测试
- [ ] 断言和日志的区别
- [ ] 最小可复现示例
- [ ] 单元测试、回归测试
- [ ] 格式化工具和静态分析工具
- [ ] 阅读编译器报错的第一条有效信息

## F. 当前教程特别建议补写的主题

### 1. 多文件通讯录
把 17-综合项目拆成：

```text
include/contact.h
src/contact.c
src/storage.c
src/main.c
tests/test_contact.c
```

### 2. 安全输入
重点练习 `fgets` + `strtol`，逐步替代直接使用 `scanf` 读取复杂输入。

### 3. 内存安全实验
故意制造越界、泄漏、悬空指针，再用 AddressSanitizer 定位并修复。

```powershell
gcc -std=c17 -Wall -Wextra -g -fsanitize=address source.c -o .build/sanitize.exe
```

### 4. 未定义行为实验
分别观察有符号溢出、越界访问、未初始化读取、错误格式说明符，并记录“为什么不能依赖当前机器的结果”。

## 学习优先级

如果时间有限，优先顺序是：

1. 未定义行为和内存安全
2. 指针的 const 组合、生命周期和所有权
3. 多文件编译和链接
4. `stdint.h`、`size_t`、错误处理
5. GDB、AddressSanitizer 和测试
6. 字节序、对齐、`restrict`、C11 原子操作

完成这些内容后，普通 C 基础才算从“会写语法”提升到“能维护和调试程序”。
