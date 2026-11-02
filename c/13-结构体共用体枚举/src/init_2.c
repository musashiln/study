#include <stdio.h>

struct Student {
     char *name;
     int age;
 };


int main(void){
     struct Student stu;
    // 访问stu的age成员
    stu.age = 27;
    printf("age = %d", stu.age);

    struct Student stu1 = {"lnj", 27};

    struct Student stu2 = {.age = 35, .name = "lnj"};

    struct Student stu3;
    stu3 = (struct Student){"lnj", 35};

    return 0;
}