#include <stdio.h>
int main(){
    float a = 0.1;
    float b = a * 10 + 0.00000000001;
    double c = 1.0 + + 0.00000000001;
    printf("b = %f\n", b);
    printf("c = %f\n", c);
    int result = b == c;
    printf("result = %i\n", result); // 0
}
