#include <stdio.h>
#include <string.h>
int main(void){
        //省略元素个数时, 不能省略末尾的\0
    // 不正确地写法，结尾没有\0 ，只是普通的字符数组
    char name4[] = {'l','n','j'};

     //   "中间不能包含\0", 因为\0是字符串的结束标志
     //    \0的作用：字符串结束的标志
    char name[] = "c\0ool";
     printf("name = %s\n",name);
// 输出结果: c


}