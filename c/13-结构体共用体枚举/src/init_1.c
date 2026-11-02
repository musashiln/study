#include <stdio.h>

// 先定义结构体类型，再定义变量
struct Student {
     char *name;
     int age;
};
struct Student stu;

// 定义结构体类型的同时定义变量
struct Student {
    char *name;
    int age;
} stu;

// 匿名结构体定义结构体变量
struct {
    char *name;
    int age;
} stu;


int main(void){
    struct Student s={"Alice",20};
    printf("%s %d\n",s.name,s.age);
    return 0;
}