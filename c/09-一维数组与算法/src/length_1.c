#include <stdio.h>
int main(void){
    int ages[4] = {19, 22, 33, 13};
    int length =  sizeof(ages)/sizeof(int);
    printf("length = %d", length);

    return 0;

}