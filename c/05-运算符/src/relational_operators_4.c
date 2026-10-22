#include <stdio.h>
int main(){
    int result1 = 3 > 4 + 7;//0
    int result2 = (3>4) + 7;//7
    int result3 = 5 != 4 + 2 * 7 > 3 == 10;//0

    printf("result1 = %i\n", result1);
    printf("result2 = %i\n", result2);
    printf("result3 = %i\n", result3);
}
