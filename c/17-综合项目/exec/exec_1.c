#include <stdio.h>


void reverse_array(int nums[], size_t n)
{
    if (n == 0) {
        return ;
    }
    for(size_t i = 0; i < n / 2; i++) {
        int temp = nums[i];
        nums[i] = nums[n - 1 - i];
        nums[n - 1 - i] = temp;
    }
}

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

int remove_first(int nums[], size_t *n, int target)
{
    if (n == NULL || *n == 0) {
        return 0;
    }
    size_t index = 0;
    if (find_first(nums, *n, target, &index)) {
        for(size_t i = index; i < *n - 1; i++) {
            nums[i] = nums[i + 1];
        }
        (*n)--;
        return 1;
    } else {
        return 0;
    }
}

int remove_at(int nums[], size_t *n, size_t index) {
    if (n == NULL || *n == 0) {
        return 0;
    } 
    if (index < 0 || index >= *n) {
        return 0;
    }
    for (size_t i = index; i < *n - 1; i++) {
        nums[index] = nums[index + 1];
    }
    (*n)--;
    return 1;
}

int insert_at(int nums[], size_t *n, size_t capacity,
              size_t index, int value)
{
    if (n == NULL || *n >= capacity || index > *n) {
        return 0;
    }
    for (size_t i = *n; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    nums[index] = value;
    (*n)++;
    return 1;
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

size_t remove_all(int nums[], size_t *n, int target)
{
    if (n == 0) {
        return 0;
    }

    size_t write = 0;
    for(size_t read = 0; read < *n; read++) {
        if (nums[read] != target) {
            nums[write] = nums[read];
            write++;
        }
    }
    size_t temp = *n;
    *n = write;
    return temp - write;
}

int main(void) {
    int nums[6] = {3, 8, 8, -5, 8};
    size_t n = 5;
    size_t capacity = sizeof(nums) / sizeof(nums[0]);

    int remove_at_flag = remove_at(nums, &n, 3);
    if(!remove_at_flag) {
        return 0;
    } else {
        for(size_t i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }
    }

    size_t delete_num = remove_all(nums, &n, 8);
    printf("\n删除所有 8 后：");
    for(size_t i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n有效长度：");
    printf("%zu", n);
    printf("\n返回值：");
    printf("%zu\n", delete_num);

    if (!insert_at(nums, &n, capacity, 0, 99)) {
        printf("插入失败\n");
    }   

    for(size_t i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    
    int sum = array_sum(nums, n);
    
    int largest = 100;
    if (array_max(nums, n, &largest)) {
        printf("\n最大值：%d\n", largest);
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

    reverse_array(nums, n);
    for(size_t i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
    int removed = remove_first(nums, &n, 8);
    for(size_t i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}