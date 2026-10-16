#include <stdio.h>
int main(void){ 
    const double pi=3.1415926535; 
    int r=2; 
    printf("area=%.2f\n",pi*r*r); 

    printf("size=%zu\n",sizeof(short)); 
    printf("size=%zu\n",sizeof(int)); 
    printf("size=%zu\n",sizeof(long)); 

    printf("size=%zu\n",sizeof(float));
    printf("size=%zu\n",sizeof(double));

    printf("size=%zu\n",sizeof(char)); 
    
    short s = 10;
    int i = 20;
    long l = 30L;
    float f = 1.5f;
    double d = 3.14;
    char c = 'A';

    printf("%hd\n", s);
    printf("%d\n", i); 
    printf("%ld\n", l); 
    printf("%f\n", f); 
    printf("%lf\n", d); 
    printf("%c\n", c); 

    return 0; 
}