#include <stdio.h>
int main(){
    //               真     &&    真
    int result = (10 == 10) && (5 != 1);
    printf("result = %i\n", result); // 1
    //          假     &&    真
    result = (10 == 9) && (5 != 1);
    printf("result = %i\n", result); // 0
    //          真     &&    假
    result = (10 == 10) && (5 != 5);
    printf("result = %i\n", result); // 0
    //          假     &&    假
    result = (10 == 9) && (5 != 5);
    printf("result = %i\n", result); // 0
}
