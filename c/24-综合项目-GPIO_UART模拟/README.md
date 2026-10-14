# 24-综合项目-GPIO_UART模拟

## 核心笔记
在 PC 上模拟一个最小裸机项目：主循环读取事件，GPIO 输出状态，UART 打印日志，所有硬件访问通过接口完成。以后移植到开发板时，只替换 platform 目录。

## 跟练提示
先手敲 src/main.c，再完成 exercises.md。把与具体芯片有关的内容写入 notes.md。
