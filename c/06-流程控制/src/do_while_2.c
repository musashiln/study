#include<stdio.h>
int main()
{
    int num = -1;
    do{
        printf("请输入密码,验证您的身份\n");
        scanf("%d", &num);
    }while(123456 != num);
    printf("主人,您终于回来了\n");
}
