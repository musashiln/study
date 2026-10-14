# 20-编译链接启动内存布局

## 核心笔记
嵌入式程序不仅有 C 源码，还要经过预处理、编译、汇编、链接。理解 .text、.rodata、.data、.bss、栈和堆，才能分析 Flash/RAM 占用。启动代码负责设置栈、复制 data、清零 bss，最后调用 main。链接脚本决定各段放在哪里。

## 跟练提示
先手敲 src/main.c，再完成 exercises.md。把与具体芯片有关的内容写入 notes.md。
