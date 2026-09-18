# 06 - C++ 工程实践

## 阶段目标

把单文件练习提升为可构建、可测试、可调试、可维护的多文件工程，并理解 C++ 编译与链接模型。

## 学习内容

1. **编译与链接模型**
   - 预处理、编译、汇编、链接
   - 声明与定义、头文件与源文件
   - include guard、`#pragma once`、前置声明
   - 内部链接、外部链接、`extern` 与 ODR
   - 静态库、动态库、符号、ABI 基础和 `extern "C"`
2. **现代 CMake**
   - target-based 写法
   - `add_library`、`add_executable`、`target_link_libraries`
   - `PUBLIC`、`PRIVATE`、`INTERFACE`
   - Debug/Release、安装、导出和依赖查找基础
3. **测试**
   - 单元测试、集成测试和回归测试
   - GoogleTest 或 Catch2
   - 测试边界、异常路径和依赖替身/Mock 基础
4. **调试和质量工具**
   - GDB、core dump、调用栈
   - AddressSanitizer、UBSan、ThreadSanitizer
   - Valgrind（Linux）和性能分析基础
   - `clang-format`、`clang-tidy`、编译警告策略
5. **工程协作**
   - Git 分支、合并、冲突处理和提交规范
   - README、API 文档与 Doxygen
   - GitHub Actions 持续集成
   - vcpkg 或 Conan 选择一个
   - Docker 与可复现开发环境基础
6. **运行期工程能力**
   - 日志级别、结构化日志和错误上下文
   - 配置文件、命令行参数和版本信息
   - 性能测量与不过早优化

## 阶段项目

开发一个多文件 C++ 日志库或传感器数据处理库，要求：

- 使用 CMake 构建库、示例程序和测试。
- 有清晰的公开接口和私有实现。
- CI 自动执行构建、测试和静态检查。
- 使用 Sanitizer 验证内存安全。
- 提供安装、使用和故障排查文档。

## 完成标准

- [ ] 能解释常见编译错误和链接错误的根因
- [ ] 能用现代 CMake 管理库、可执行文件和测试
- [ ] 能编写有效的单元测试与集成测试
- [ ] 能使用 GDB、Sanitizer 和静态检查工具排错
- [ ] 能创建 CI 工作流并保持主分支构建通过
- [ ] 能生成或维护清楚的工程文档
