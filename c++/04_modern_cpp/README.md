# 04 - 现代 C++ 与标准库

## 阶段目标

熟练使用标准库解决实际问题，建立清晰的所有权模型，并掌握 C++17 主线和常用 C++20 特性。

## 学习内容

1. **容器与迭代器**
   - `vector`、`array`、`deque`、`list`
   - `map`、`unordered_map`、`set`、`unordered_set`
   - 迭代器、范围 `for`、失效规则和复杂度
2. **算法与可调用对象**
   - 查找、排序、变换、累计和划分
   - Lambda 捕获规则
   - 函数对象与 `std::function` 的使用和代价
3. **智能指针与所有权**
   - `unique_ptr`、`shared_ptr`、`weak_ptr`
   - 所有权、借用关系、循环引用
   - 优先使用值和 `unique_ptr`，谨慎使用共享所有权
4. **移动与泛型**
   - 左值、右值和值类别基础
   - 移动语义、`std::move`、完美转发
   - 函数模板、类模板、类型推导和模板实例化
5. **实用类型与库**
   - `optional`、`variant`、`any`
   - `string_view`、结构化绑定
   - `chrono`、`filesystem`、随机数
   - 异常与错误码的取舍
6. **C++20 提升**
   - `span`、Concepts、Ranges
   - `jthread`、`stop_token` 作为并发阶段的提升内容
   - C++23 只做后续了解，不作为主线依赖

## 实践任务

- 使用 STL 重构基础阶段的成绩统计程序。
- 编写传感器记录分析器：读取文件、过滤异常值、统计并排序。
- 用 `variant` 表示多种消息，用 `optional` 表示可能缺失的结果。
- 比较 `vector`、`list`、`map` 和 `unordered_map` 在不同任务中的适用性。

## 完成标准

- [ ] 能根据访问方式和复杂度选择合适容器
- [ ] 能组合标准算法和 Lambda，避免不必要的手写循环
- [ ] 能明确说明对象所有权并正确选择智能指针
- [ ] 能解释移动语义，避免移动后误用对象
- [ ] 能编写并使用基础函数模板和类模板
- [ ] 能使用 `optional`、`variant`、`chrono` 和 `filesystem`
