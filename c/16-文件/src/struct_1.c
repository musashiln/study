#include <stdio.h>

typedef struct{
    char *name;
    int age;
    double height;
} Person;

int main()
{
    Person p1 = {"lnj", 35, 1.88};
//    printf("name = %s\n", p1.name);
//    printf("age = %i\n", p1.age);
//    printf("height = %lf\n", p1.height);

    FILE *fp = fopen("person.stu", "wb+");
    fwrite(&p1, sizeof(p1), 1, fp);

    rewind(fp);
    Person p2;
    fread(&p2, sizeof(p2), 1, fp);
    printf("name = %s\n", p2.name);
    printf("age = %i\n", p2.age);
    printf("height = %lf\n", p2.height);

    return 0;
}
