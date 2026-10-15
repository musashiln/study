# 26 指针与内存安全

## 学习目标

掌握 const 指针组合、void 指针、指针运算、对象生命周期、所有权、悬空指针、重复释放、泄漏和安全 realloc。

## 1. const 指针

~~~c
const int *p1;             /* 不能通过 p1 改数据，p1 可改指向 */
int *const p2 = NULL;      /* p2 不可改指向，可改数据 */
const int *const p3 = NULL;/* 两者都不可改 */
~~~

函数读取数组时优先使用 const int *，表达“不修改调用者数据”。

## 2. 生命周期和所有权

不能返回局部变量地址：

~~~c
int *bad(void)
{
    int local = 1;
    return &local;
}
~~~

动态对象必须明确谁申请、谁使用、谁释放。建议在接口注释中写明所有权。

~~~c
int *make_value(int value)
{
    int *p = malloc(sizeof *p);
    if (p != NULL) *p = value;
    return p;       /* 调用者负责 free */
}
~~~

## 3. 指针运算和 void *

指针加一移动一个元素；只有同一数组中的指针相减和比较才合法。void * 可以保存任意对象地址，但解引用前必须转换为正确类型。

## 4. realloc 安全写法

不要直接覆盖原指针：

~~~c
int *tmp = realloc(data, new_count * sizeof *data);
if (tmp != NULL) data = tmp;
/* 失败时 data 仍然有效 */
~~~

还要检查乘法溢出和 new_count 的合理范围。

## 5. 常见错误和工具

越界、use-after-free、double free、泄漏、未检查 malloc 都是高频错误。释放后可置 NULL：

~~~c
free(p);
p = NULL;
~~~

AddressSanitizer：

~~~powershell
gcc -std=c17 -Wall -Wextra -g -fsanitize=address src/main.c -o .build/ch26-sanitize.exe
~~~

## 操作步骤

1. 手敲并运行 src/main.c。
2. 加入动态数组。
3. 故意访问 array[length]，用 AddressSanitizer 看报告。
4. 修复后再次运行。
5. 为链表写清申请和释放责任。

## 练习

1. 声明三种 const 指针。
2. 写动态数组安全扩容函数。
3. 制造一次泄漏和一次 use-after-free，再修复。
4. 写 destroy_list 并证明所有节点都释放。

## 完成标准

写动态内存前先说明所有权，并能使用工具定位内存错误。
