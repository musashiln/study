#include <stdio.h>

int max(int a,int b){
    return a>b?a:b;
} 

int main(void){
    printf("%d\n",max(3,8));
    return 0;
}