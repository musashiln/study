#include <stdio.h>
void add(int*p){(*p)++;} int main(void){int n=41;add(&n);printf("%d\n",n);return 0;}