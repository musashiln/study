#include <stdio.h>

int main() {
    // exer1
    int a = 0;
    scanf("%d", &a);
    if (a >= 100 && a <= 200) {
        printf("%d 在100到200之间\n", a);
    } else {
        printf("%d 不在100到200之间\n", a);
    }

    // exer2
    printf("%d\n", 6 == 6 == 6);

    // exer3
    int m1 = 0, m2 = 0, m3 = 0;
    scanf("%d %d %d", &m1, &m2, &m3);
    printf("max number: %d\n", m1 > m2? (m1 > m3? m1 : m3) : (m2 > m3? m2 : m3));

    // exer4
    int c1 = 10, c2 = 20;
    int c = c1 + c2;
    c1 = c - c1;
    c2 = c - c1;
    printf("c1 = %d, c2 = %d\n", c1, c2);
    
    
}