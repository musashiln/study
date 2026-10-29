#include <stdio.h>
#include <string.h>
int main(void){
    char name[] = "it666";
    int size = sizeof(name);// 包含\0
    printf("size = %d\n", size); //输出结果:6

    char name2[] = "it666";
    size_t len = strlen(name2);
    printf("len = %lu\n", len); //输出结果:5

    char oldStr[100] = "welcome to";
    char newStr[20] = " lnj";
    strcat(oldStr, newStr);
    puts(oldStr); //输出: welcome to lnj"

    char oldStr1[100] = "welcome to";
    char newStr1[50] = " lnj";
    strcpy(oldStr1, newStr1);
    puts(oldStr1); // 输出结果:  lnj // 原有数据会被覆盖

    char oldStr2[100] = "0";
    char newStr2[50] = "1";
    printf("%d\n", strcmp(oldStr2, newStr2)); //输出结果:-1
    char oldStr3[100] = "1";
    char newStr3[50] = "1";
    printf("%d\n", strcmp(oldStr3, newStr3));  //输出结果:0
    char oldStr4[100] = "1";
    char newStr4[50] = "0";
    printf("%d\n", strcmp(oldStr4, newStr4)); //输出结果:1

}