#include <stdio.h>
int main(void) {
    int ages[3] = {4, 6, 9};
    int nums[] = {1,2,3,5,6};
    int nums1[10] = {1,2};
    int nums2[5] = {[4] = 3,[1] = 2};
    int nums3[] = {[4] = 3};
    int nums4[3];
    nums4[0] = 1;
    nums4[1] = 2;
    nums4[2] = 3;

    // int ages1[3];
    // ages1 = {4, 6, 9}; // 报错

    // // []中不能放变量
    // int number = 10;
    // int ages[number]; // 老版本的C语言规范不支持
    // printf("%d\n", ages[4]);

    return 0;

}