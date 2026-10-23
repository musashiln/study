#include <stdio.h>

int main() {
    while(1) {
        while(2) {
            break;// 只对while2有效, 不会影响while1
        }
        printf("while1循环体\n");
    }


}