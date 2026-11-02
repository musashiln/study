#include <stdio.h>
void test();

//定义一个全局结构体,作用域到文件末尾
struct Person{
    int age;
    char *name;
};

int main()
{
    //定义局部结构体名为Person,会屏蔽全局结构体
    //局部结构体作用域,从定义开始到“}”块结束
    struct Person{
        int age;
    };
    // 使用局部结构体类型
    struct Person pp;
    pp.age = 50;
    // pp.name = "zbz";

    test();
    return 0;
}

void test() {

    //使用全局的结构体定义结构体变量p
    struct Person p = {10,"sb"};
    printf("%d,%s\n",p.age,p.name);
}
