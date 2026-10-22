#include <stdio.h>
int main(){
    int a = 10;
    double b = 3.14;
    // 由于sizeof的优先级比+号高, 所以会先计算sizeof(a);
    // a是int类型, 所以占4个字节得到结果4
    // 然后再利用计算结果和b相加, 4 + 3.14 = 7.14
    double res = sizeof a+b;
    printf("res = %lf\n", res); // 7.14
}
