#include <stdio.h>

void selectSort(int numbers[], int length);
void swapEle(int array[], int i, int j);

// 选择排序
void selectSort(int numbers[], int length) {
    
    // 外循环为什么要-1?
    // 最后一位不用比较, 也没有下一位和它比较, 否则会出现错误访问
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length - 1; j++) {
            // 1.用当前元素和后续所有元素比较
            if (numbers[i] > numbers[j + 1]) {
                //  2.一旦发现大于就交换位置
                swapEle(numbers, i, j + 1);
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

int main() {
    int numbers[10] = {5, 38, 9, 20, 22, 13, 42, 2, 65, 3};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    selectSort(numbers, length);
    for(int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}