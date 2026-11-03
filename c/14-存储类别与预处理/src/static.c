/*
对局部变量的作用
延长局部变量的生命周期,从程序启动到程序退出,但是它并没有改变变量的作用域
定义变量的代码在整个程序运行期间仅仅会执行一次
*/


#include <stdio.h>
void test();
int main()
{
    test();
    test();
    test();

    return 0;
}
void test(){
    static int num = 0; // 局部变量
    num++; 
    // 如果不加static输出 1 1 1
    // 如果添加static输出 1 2 3
    printf("num = %i\n", num); 
}
