#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4  )
    {
        printf("Wrong !");
        printf("PLEASE USE: <Ceasar> <filestart> <offset> <file end>");
    }
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[3], "w+");
    char c = fgetc(fp1);
    do
    {
        fputc(c + atoi(argv[2]), fp2);
        c = fgetc(fp1);
    } while (c != EOF);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
