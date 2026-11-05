#include <stdio.h>

int main()
{
    FILE *fp;
   fp = fopen("file.txt","w+");
   fputs("123456789", fp);

   fseek( fp, 7, SEEK_SET );
   fputs("lnj", fp);
   fclose(fp);
    return 0;
}
