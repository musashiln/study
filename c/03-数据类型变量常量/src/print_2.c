#include <stdio.h>
int main(){
    // 实际位数小于指定宽度
    int a = 1;
    printf("a =|%d|\n", a); // |1|
    printf("a =|%5d|\n", a); // |    1|
    // 实际位数大于指定宽度
    int b = 1234567;
    printf("b =|%d|\n", b); // |1234567|
    printf("b =|%5d|\n", b); // |1234567|
}
