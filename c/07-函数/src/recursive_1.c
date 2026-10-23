#include <stdio.h>

// 能用循环实现的功能,用递归都可以实现
// 递归常用于"回溯", “树的遍历”,"图的搜索"等问题

void getNumber();
void getNumber2();

int main() {
    getNumber2();
}

void getNumber2(){
    int number = -1;
    printf("请输入一个正数abc\n");
    scanf("%d", &number);
    if (number < 0) {
//        负数
        getNumber2();
    }else{
//        正数
       printf("number = %d\n", number);
    }
}

void getNumber(){
    int number = -1;
    while (number < 0) {
        printf("请输入一个正数\n");
        scanf("%d", &number);
    }

    printf("number = %d\n", number);
}
