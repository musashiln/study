#include <stdio.h>

void bubbleSort(int numbers[], int length);
void swapEle(int array[], int i, int j);

void insertSort(int numbers[], int length) {
    //  1.从第一个元素开始依次取出所有用于比较元素
    for (int i = 1; i < length; i++)
    {
        // 2.遍历取出前面元素进行比较
        for(int j = i; j > 0; j--)
        {
            // 3.如果前面一个元素大于当前元素,就交换位置
            if(numbers[j-1] > numbers[j]){
                int temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;
            }else{
                break;
            }
        }
    }
}


int main(void) {
    int numbers[10] = {5, 38, 9, 20, 22, 13, 42, 2, 65, 3};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    insertSort(numbers, length);
    for(int i = 0; i < length; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}