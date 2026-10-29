#include <stdio.h>
#include <string.h>
int main(void){
    char chs[] = "lnj";
    printf("%s\n", chs);

    char name[] = {'c', 'o', 'o', 'l' , '\0'};
    char name2[] = {'l', 'n', 'j'};
    printf("name2 = %s\n", name2); // 输出结果: lnjcool

    char ch[10];
    scanf("%s",ch);
    printf("%s\n", ch);

}