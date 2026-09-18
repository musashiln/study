# 01 - C++ 基础

## 阶段目标

掌握结构化程序设计，能够把一个简单需求拆分为变量、分支、循环和函数，并对无效输入进行处理。

## 学习内容

1. **程序结构与输入输出**
   - `#include`、`main`、语句、注释和命名空间
   - `std::cout`、`std::cin`、换行和格式化输出
2. **变量与类型**
   - 声明、初始化、赋值和作用域
   - `int`、固定宽度整数、浮点数、`char`、`bool`、`std::string`
   - `const`、`constexpr` 和字面量
   - 隐式转换、显式转换、整数溢出和浮点误差初步
3. **表达式与控制流**
   - 算术、比较、逻辑、赋值和位运算符
   - `if`、`switch`、条件表达式
   - `for`、`while`、`do while`、`break`、`continue`
4. **函数**
   - 声明、定义、参数、返回值和调用栈
   - 值传递、引用传递和 `const` 引用初步
   - 函数重载、默认参数和递归入门
5. **组织与建模**
   - `enum class`
   - 命名空间
   - 输入验证、错误状态与基本防御式编程

## 建议课程目录

```text
lesson01_hello
lesson02_variables
lesson03_input_and_arithmetic
lesson04_conditions
lesson05_loops
lesson06_functions_and_scope
lesson07_enum_namespace_and_conversion
lesson08_basic_error_handling
```

## 阶段练习

制作一个命令行成绩统计程序：读取多名学生成绩，拒绝非法输入，输出最高分、最低分、平均分和等级统计。先使用基础语法实现，后续阶段再用容器和类重构。

## 完成标准

- [ ] 能独立选择合适的基础类型并说明原因
- [ ] 能正确使用分支、循环和函数拆分问题
- [ ] 能解释作用域、值传递和引用传递
- [ ] 能处理输入失败、边界值和错误选项
- [ ] 能使用 `const`、`constexpr`、`enum class` 和命名空间
- [ ] 阶段练习编译无警告，并有清楚的运行说明
