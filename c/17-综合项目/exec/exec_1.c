#include <stdio.h>

size_t replace_negative(int nums[], size_t n)
{
    if (n == 0) {
        return 0;
    }
    
    size_t count = 0;
    for(size_t i = 0; i < n; i++) {
        if (nums[i] < 0) {
            count++;
            nums[i] = 0;
        } 
    }
    return count;
}

size_t count_value(const int nums[], size_t n, int target)
{
    size_t count = 0;
    for(size_t i = 0; i < n; i++) {
        if (nums[i] == target) {
            count++;
        } 
    }
    return count;
}

int find_first(const int nums[], size_t n, int target, size_t *index)
{
    if (n == 0) {
        return 0;
    }
    for(size_t i = 0; i < n; i++) {
        if (nums[i] == target) {
            *index = i;
            return 1;
        }
    }
    return 0;
}

int array_max(const int nums[], size_t n, int *result)
{
    if (n == 0) {
        return 0;
    }

    int max = nums[0];

    for(size_t i = 1; i < n; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    *result = max;
    return 1;
}

int array_min(const int nums[], size_t n, int *result)
{
    if (n == 0) {
        return 0;
    }

    int min = nums[0];

    for(size_t i = 1; i < n; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    *result = min;
    return 1;
}


int array_sum(const int nums[], size_t n)
{
    int sum = 0;
    for(size_t i = 0; i < n; i++) {
        sum += nums[i];
    }
    return sum;
}

size_t count_positive(const int nums[], size_t n)
{
    size_t count = 0;
    for(size_t i = 0; i < n; i++) {
        if (nums[i] > 0) {
            count++;
        }
    }
    return count;
}

int main(void) {
    int nums[] = {3, -2, 0, -5, 8};
    // int nums[] = {-3, -2, -7, -1, -5, -8};
    size_t n = sizeof(nums) / sizeof(nums[0]);
    
    int sum = array_sum(nums, n);
    
    int largest = 100;
    if (array_max(nums, n, &largest)) {
        printf("最大值：%d\n", largest);
    } else {
        printf("没有元素，无法求最大值\n");
        return 0;
    }

    int smallest = 100;
    if (array_min(nums, n, &smallest)) {
        printf("最小值：%d\n", smallest);
    } else {
        printf("没有元素，无法求最小值\n");
        return 0;
    }

    size_t max_count = count_value(nums, n, largest);

    size_t count = count_positive(nums, n);
    

    size_t index = 0;
    if (find_first(nums, n, 9, &index)) {
        printf("第一次出现的下标：%zu\n", index);
    } else {
        printf("没有该元素\n");
    }

    size_t max_index = 0;
    if (find_first(nums, n, largest, &max_index)) {
        printf("最大值第一次出现的下标：%zu\n", max_index);
    } else {
        printf("没有元素，无法求最大值第一次出现的下标\n");
        return 0;
    }

    printf("总和：%d\n", sum);
    printf("正数个数：%zu\n", count);
    printf("最大值出现的次数：%zu\n", max_count);

    size_t negative_count = replace_negative(nums, n);
    for(size_t i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n修改次数：%zu\n", negative_count);

    return 0;
}