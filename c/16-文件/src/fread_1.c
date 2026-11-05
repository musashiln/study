#include <stdio.h>

int main()
{

    FILE *fp = fopen("test.txt", "wb+");
    int ages[4] = {1, 3, 5, 6};
    fwrite(ages, sizeof(ages), 1, fp);
    rewind(fp);
    int data;
    while(fread(&data, sizeof(int), 1, fp) > 0){
        printf("data = %i\n", data);
    }
    return 0;
}
