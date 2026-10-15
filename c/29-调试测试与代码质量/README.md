# 29 调试、测试与代码质量

## 学习目标

建立编译、测试、断点、单步、调用栈、断言、日志和回归测试流程。

## 1. 编译警告

~~~powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -g src/main.c -o .build/ch29.exe
~~~

先理解警告，不要立刻用 -Wno 关闭。

## 2. GDB

~~~powershell
gdb .build/ch29.exe
~~~

常用命令：

~~~text
break main
run
next
step
print variable
backtrace
continue
quit
~~~

VS Code 中 F5 启动；F10 步过；F11 步入；Shift+F11 跳出。

## 3. 测试层次

单元测试测试一个函数；集成测试测试模块协作；回归测试保证修复不破坏旧功能；边界测试覆盖空、单元素、满容量、重复值和非法输入。

## 4. assert 和日志

assert 检查内部不变量。日志记录运行过程。用户输入错误、文件失败和内存不足必须走正常错误处理。

## 操作步骤

1. 给顺序表补充空表、满表、非法下标测试。
2. 在 main 和关键函数设置断点。
3. 查看调用栈和局部变量。
4. 故意引入 bug，先让测试失败，再修复。
5. 保留可重复的编译测试命令。

## 练习

1. 为链表写 10 个边界测试。
2. 为排序写有序、逆序、重复值和空数组测试。
3. 处理 -Wall -Wextra -Wpedantic 的所有警告。
4. 写回归测试 PowerShell 命令。

## 完成标准

能说明问题如何复现、预期和实际结果、最小范围、修复方法和验证证据。
