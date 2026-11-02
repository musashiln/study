#include <stdio.h>

struct Student {
    const char *name;
    int age;
};

int main(void)
{
    struct Student stu[2] = {
        {"lnj", 35},
        {"zs", 18}
    };

    struct Student stu1[2];

    stu1[0] = (struct Student){"lnj", 35};
    stu1[1] = (struct Student){"zs", 18};

    for (int i = 0; i < 2; i++) {
        printf("stu:  name=%s, age=%d\n",
               stu[i].name, stu[i].age);

        printf("stu1: name=%s, age=%d\n",
               stu1[i].name, stu1[i].age);
    }

    return 0;
}