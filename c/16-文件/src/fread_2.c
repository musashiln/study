#include <stdio.h>

typedef struct{
    char *name;
    int age;
    double height;
} Person;

int main()
{
    Person ps[] = {
      {"zs", 18, 1.65},
      {"ls", 21, 1.88},
      {"ww", 33, 1.9}
    };


    FILE *fp = fopen("person.stu", "wb+");
    fwrite(&ps, sizeof(ps), 1, fp);

    rewind(fp);
    Person p;
    while(fread(&p, sizeof(p), 1, fp) > 0){
        printf("name = %s\n", p.name);
        printf("age = %i\n", p.age);
        printf("height = %lf\n", p.height);
    }
    return 0;
}
