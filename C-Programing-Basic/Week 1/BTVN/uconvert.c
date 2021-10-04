#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 =fopen("TemporaryFile.txt", "w+");
    char c = fgetc(fp1);
    do
    {
        fputc(toupper(c), fp2);
        c = fgetc(fp1);
    } while (c != EOF);
    fclose(fp1);
    fclose(fp2);
    remove(argv[1]);
    rename("TemporaryFile.txt", argv[1]);
    return 0;
}
