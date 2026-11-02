#include <stdio.h>

struct Person{
    char *name;
    int age;
};

int main(){

    struct Person p1 = {"lnj", 35};
    struct Person p2;
    p2 = p1;
    p2.name = "zs"; // 修改p2不会影响p1
    printf("p1.name = %s\n", p1.name); // lnj
    printf("p2.name = %s\n", p2.name); //  zs
}