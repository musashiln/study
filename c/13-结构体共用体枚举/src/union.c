#include <stdio.h>

union Test{
        int age;
        char ch;
};


int main(){

    union Test t;
    printf("sizeof(p) = %i\n", sizeof(t));//4

    t.age = 33;
    printf("t.age = %i\n", t.age); // 33
    t.ch = 'a';
    printf("t.ch = %c\n", t.ch); // a
    printf("t.age = %i\n", t.age); // 97
}