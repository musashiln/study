#include <stdio.h>

int main() {

    int num = 3;
    switch(1){ 
    case 1:
        printf("星期一\n");
        break;
    case 'a':
        printf("星期二\n");
        break;
    // case num: // 报错
    //     printf("星期三\n");
    //     break;
    // case 4.0: // 报错
    //     printf("星期四\n");
    //     break;
    default:
        printf("回火星去\n");
        break;
    }
}
