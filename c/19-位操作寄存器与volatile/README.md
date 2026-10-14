# 19-位操作寄存器与volatile

## 核心笔记
MCU 外设通常通过内存映射寄存器控制。用掩码读写单个位或位域；volatile 告诉编译器该内存可能被硬件或中断异步修改，不能擅自缓存。volatile 不能保证原子性、互斥或线程安全。

## 跟练提示
先手敲 src/main.c，再完成 exercises.md。把与具体芯片有关的内容写入 notes.md。
