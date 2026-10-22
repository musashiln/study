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
    
    short s;
    int i;
    long l;
    float f;
    double d;
    char c;

    printf("%hd\n", s);
    printf("%d\n", i); 
    printf("%ld\n", l); 
    printf("%f\n", f); 
    printf("%lf\n", d); 
    printf("%c\n", c); 

    return 0; 
}