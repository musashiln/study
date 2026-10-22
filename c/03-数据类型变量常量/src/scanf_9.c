#include <stdio.h>
int main(){
    int num1;
    int num2;
    char ch1;
    scanf("%d%c%d", &num1, &ch1, &num2);
    printf("num1 = %d, ch1 = %c, num2 = %d\n", num1, ch1, num2);
    //fflush(stdin); // 清空输入缓存区
    setbuf(stdin, NULL); // 清空输入缓存区
    char ch2;
    int num3;
    scanf("%c%d",&ch2, &num3);
    printf("ch2 = %c, num3 = %d\n", ch2, num3);
}
