# 09 - ROS 2

## 阶段目标

掌握 ROS 2 的软件组织、通信和调试方式，能够完成一个经过测试的机器人仿真项目，并为连接真实硬件做好准备。

> 选择一个仍在支持期内、与目标平台兼容的 ROS 2 发行版，并使用对应 Ubuntu 版本。具体版本随学习时间更新，不在路线中写死。

## 学习内容

1. **环境与工作区**
   - ROS 2 安装、环境脚本与 overlay
   - 工作区、功能包、`colcon`、`ament_cmake`
   - 包清单、依赖管理和 C++ 节点
2. **通信基础**
   - 节点、话题、服务、动作、参数
   - 自定义 `msg`、`srv`、`action`
   - DDS 概念与发现机制
   - Reliability、Durability、History、Depth 等 QoS 策略
3. **执行模型**
   - 回调、Executor、单线程与多线程 Executor
   - Callback Group、共享状态与线程安全
   - Lifecycle Node、Component 和进程内通信
4. **机器人基础设施**
   - TF2、时间戳与坐标变换
   - URDF、Xacro、机器人模型
   - Launch 文件和参数配置
   - `rosbag2`、RViz2 和仿真器
5. **调试、测试与性能**
   - `ros2 node/topic/service/action/param` 命令
   - `rqt_graph`、日志、TF 树排错
   - 单元测试、Launch/集成测试
   - tracing、通信延迟和性能分析基础
6. **控制与方向项目**
   - `ros2_control` 架构和控制器
   - 移动机器人：里程计、IMU、激光雷达、SLAM Toolbox、Nav2
   - 机械臂：正逆运动学基础、MoveIt 2、硬件接口
   - 移动机器人与机械臂方向先选择一个深入

## 建议实践顺序

1. 发布/订阅温度或传感器数据。
2. 使用服务修改配置，使用动作执行长任务。
3. 创建自定义接口、Launch 和参数文件。
4. 建立 URDF/Xacro 模型和完整 TF 树。
5. 使用 rosbag 记录、回放并复现故障。
6. 完成差速小车仿真，或完成机械臂规划仿真。

## 完成标准

- [ ] 能创建、构建和组织 ROS 2 C++ 功能包
- [ ] 能正确选择话题、服务、动作和参数
- [ ] 能根据场景配置 QoS 并解释通信不匹配
- [ ] 能理解 Executor/Callback Group 带来的并发行为
- [ ] 能构建并排查 URDF、TF2 和 Launch 系统
- [ ] 能使用命令行、RViz、rosbag 和日志复现问题
- [ ] 完成一个有自动化测试的方向项目
