#include <stdio.h>
#include <string.h>
int main(void){
    char name[9] = "lnj"; //在内存中以“\0”结束， \0ASCII码值是0
    char name1[9] = {'l','n','j','\0'};
    char name2[9] = {'l','n','j',0};
    // 当数组元素个数大于存储字符内容时, 未被初始化的部分默认值是0, 所以下面也可以看做是一个字符串
    char name3[9] = {'l','n','j'};

}