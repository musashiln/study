#include <stdio.h>
int main(){
    int a = 10;
    int b = 5;
    int c = 20;
    int d = 10;
    // 结合性是从右至左, 所以会先计算:后面的内容
    // int res = a>b?a:(c>d?c:d);
    // int res = a>b?a:(20>10?20:10);
    // int res = a>b?a:(20);
    // 然后再计算最终的结果
    // int res = 10>5?10:(20);
    // int res = 10;
    int res = a>b?a:c>d?c:d;
    printf("res = %i\n", res); //10
}
