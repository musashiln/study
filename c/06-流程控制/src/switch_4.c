#include <stdio.h>

int main() {

    int num = 2;
    switch(num){
    case 1:
        printf("星期一\n");
        break;
    case 2:
        printf("星期二\n"); // 被输出
    case 3:
        printf("星期三\n"); // 被输出
    default:
        printf("回火星去\n"); // 被输出
        break;
    }
}
