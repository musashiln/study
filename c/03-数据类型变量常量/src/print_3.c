#include <stdio.h>
int main(){
    int a = 1;
    int b = -1;
    // -号标志
    printf("a =|%d|\n", a); // |1|
    printf("a =|%5d|\n", a); // |    1|
    printf("a =|%-5d|\n", a);// |1    |
    // +号标志
    printf("a =|%d|\n", a); // |1|
    printf("a =|%+d|\n", a);// |+1|
    printf("b =|%d|\n", b); // |-1|
    printf("b =|%+d|\n", b);// |-1|
    // 0标志
    printf("a =|%5d|\n", a); // |    1|
    printf("a =|%05d|\n", a); // |00001|
    // 空格标志
    printf("a =|% d|\n", a); // | 1|
    printf("b =|% d|\n", b); // |-1|
    // #号
    int c = 10;
    printf("c = %o\n", c); // 12
    printf("c = %#o\n", c); // 012
    printf("c = %x\n", c); // a
    printf("c = %#x\n", c); // 0xa
}
