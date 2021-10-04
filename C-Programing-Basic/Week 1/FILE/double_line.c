#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w+");
    char c = fgetc(fp1);
    do
    {
        fputc(c,fp2);
        if (c == '\n')
        {
            fputc('\n', fp2);
        }      
        c = fgetc(fp1);
    } while (c != EOF);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
