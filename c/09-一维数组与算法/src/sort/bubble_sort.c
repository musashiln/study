#include <stdio.h>

void bubbleSort(int numbers[], int length);
void swapEle(int array[], int i, int j);

// 冒泡排序
void bubbleSort(int numbers[], int length) {
    for (int i = 0; i < length; i++) {
        // -1防止`角标越界`: 访问到了不属于自己的索引
        for (int j = 0; j < length - i - 1; j++) {
           //  1.用当前元素和相邻元素比较
            if (numbers[j] > numbers[j + 1]) {
                //  2.一旦发现大于就交换位置
                swapEle(numbers, j, j + 1);
            }
        }
    }
}
// 交换两个元素的值, i/j需要交换的索引
void swapEle(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}


int main(void) {
    int numbers[10] = {5, 38, 9, 20, 22, 13, 42, 2, 65, 3};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    bubbleSort(numbers, length);
    for(int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}