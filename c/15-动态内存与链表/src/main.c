#include <stdio.h>
#include <stdlib.h>
int main(void){int*p=malloc(3*sizeof*p);if(!p)return 1;free(p);return 0;}