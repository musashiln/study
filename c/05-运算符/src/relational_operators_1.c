#include <stdio.h>
int main(){
    int result = 10 > 5;
    printf("result = %i\n", result); // 1
    result = 5 < 10;
    printf("result = %i\n", result); // 1
    result = 5 > 10;
    printf("result = %i\n", result); // 0
    result = 10 >= 10;
    printf("result = %i\n", result); // 1
    result = 10 <= 10;
    printf("result = %i\n", result); // 1
    result = 10 == 10;
    printf("result = %i\n", result); // 1
    result = 10 != 9;
    printf("result = %i\n", result); // 1
}
