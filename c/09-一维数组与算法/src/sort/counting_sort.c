#include <stdio.h>
int main()
{
    // 待排序数组
    int nums[5] = {3, 1, 2, 0, 3};
    // 用于排序数组
    int newNums[4] = {0};
    // 计算待排序数组长度
    int len = sizeof(nums) / sizeof(nums[0]);
    // 遍历待排序数组
    for(int i = 0; i < len; i++){
        // 取出待排序数组当前值
        int index = nums[i];
        // 将待排序数组当前值作为排序数组索引
        // 将用于排序数组对应索引原有值+1
        newNums[index] = newNums[index] +1;
    }
    
    // 计算待排序数组长度
    int len2 = sizeof(newNums) / sizeof(newNums[0]);
    // 输出排序数组索引, 就是排序之后结果
    for(int i = 0; i < len2; i++){
        for(int j = 0; j < newNums[i]; j++){
            printf("%i\n", i);
        }
    }
    /*
    // 计算待排序数组长度
    int len2 = sizeof(newNums) / sizeof(newNums[0]);
    // 还原排序结果到待排序数组
    for(int i = 0; i < len2; i++){
        int index = 0;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < newNums[i]; j++){
                nums[index++] = i;
            }
        }
    }
    */
    return 0;
}
