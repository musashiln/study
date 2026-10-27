#include <stdio.h>

int arrayMax(int a[], int count) {
    int max = a[0];
    for(int i = 0; i < count; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int main(void){
// 设计一个函数int arrayMax(int a[], int count)找出数组元素的最大值
    int a[5] = {20, 10, 15, 16, 30};
    int count = 5;
    int max = arrayMax(a, count);
    printf("max = %d\n", max);

// 从键盘输入3个0-9的数字,然后输出0~9中哪些数字没有出现过
    int n1 = 0, n2 = 0, n3 = 0;
    printf("从键盘输入3个0-9的数字:\n");
    scanf("%d %d %d", &n1, &n2, &n3);
    int a1[3] = {n1, n2, n3};
    int a2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 10; j++) {
            if (a1[i] == a2[j]) {
                a3[j] = 1;
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        if (a3[i] == 0) {
            printf("%d ", a2[i]);
        }
    }
    printf("\n");
// 要求从键盘输入6个0~9的数字,排序后输出

}
