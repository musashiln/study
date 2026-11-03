#include <stdio.h>
#define SCORE 67

int main(void) {
    #if SCORE > 90
        printf("优秀\n");
    #else
        printf("不及格\n");
    #endif

}
