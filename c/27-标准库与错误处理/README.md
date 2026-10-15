# 27 标准库与错误处理

## 学习目标

掌握 stdint.h、stdbool.h、stddef.h、limits.h、assert.h、errno.h、ctype.h、stdlib.h、string.h，学会输入转换、qsort、bsearch、断言和错误码。

## 1. 类型和范围

stdint.h 提供 uint32_t 等固定宽度类型；stddef.h 提供 size_t；stdbool.h 提供 bool；limits.h 提供整型边界。数组长度和字符串长度使用 size_t。

## 2. fgets 加 strtol

复杂交互不要直接依赖 scanf。先读取整行，再转换：

~~~c
char line[64];
char *end = NULL;
if (fgets(line, sizeof line, stdin) == NULL) return 1;
errno = 0;
long value = strtol(line, &end, 10);
if (errno != 0 || end == line) {
    fputs("invalid number", stderr);
    return 1;
}
~~~

还应检查 end 后是否只剩空白，并检查 value 是否在目标类型范围内。

## 3. assert、errno 和错误码

assert 检查程序员不变量，不用于处理用户输入错误。运行时错误应该返回错误码并让调用者决定处理方式。

~~~c
enum { OK = 0, ERR_INVALID = 1, ERR_NOMEM = 2 };
~~~

## 4. qsort 和 bsearch

qsort 的比较函数不能直接返回 a-b，因为可能溢出：

~~~c
static int compare_int(const void *left, const void *right)
{
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a > b) - (a < b);
}
~~~

bsearch 要求数据已经按相同规则排序。

## 操作步骤

1. 用 fgets 读取数字。
2. 用 strtol 检查非法字符和溢出。
3. 用 qsort 排序整数和结构体。
4. 用 bsearch 查找。
5. 为文件、内存和输入错误设计不同错误码。

## 练习

1. 实现 read_int。
2. 统计字符、数字、空白。
3. 写返回错误码的文件读取函数。
4. 用 qsort 按结构体年龄排序。

## 完成标准

能检查标准库返回值，能区分不同失败原因，不再用 scanf 处理复杂输入。
