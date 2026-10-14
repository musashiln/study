#include <stdio.h>
struct Student{char name[32];int age;};int main(void){struct Student s={"Alice",20};printf("%s %d\n",s.name,s.age);return 0;}