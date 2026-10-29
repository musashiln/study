#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[]="I love lnj!";
    printf("%s\n",string);

    // 数组名保存的是数组第0个元素的地址, 指针也可以保存第0个元素的地址
    char *str = "abc";
    printf("%s\n",str);
    for(int i = 0; i < (int)strlen(str);i++){
        printf("%c\n", *(str+i)); 
    }
    //   + 使用字符数组来保存的字符串是保存栈里的,保存栈里面东西是可读可写,所有可以修改字符串中的的字符
    //   + 使用字符指针来保存字符串,它保存的是字符串常量地址,常量区是只读的,所以我们不可以修改字符串中的字符
    printf("%s\n",str);
    *(str+2) = 'y'; // 错误
    printf("%c\n",*(str+2));
    printf("%s\n",str);

    // 错误的原因是:str是一个野指针,他并没有指向某一块内存空间
    // 所以不允许这样写如果给str分配内存空间是可以这样用 的
    char *str;
    scanf("%s", str);


    return 0;
}