#include <stdio.h>

int main() {
    switch(1){
    case 1:{
        int num = 10;
        printf("num = %i\n", num);
        printf("星期一\n");
        break;
        }
    case 2:
        printf("星期一\n");
        break;
    default:
        printf("回火星去\n");
        break;
    }
}
