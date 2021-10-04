#include <stdio.h>

int main(int argc, char *argv[])
{
    char firstchar[80];
    FILE *fp1;
    fp1 = fopen(argv[1]/*"news.txt"*/, "r+");
    if (fp1 == NULL)
    {
        printf("Error: Cannot open file !");
        return -1;
    }
    
    char ch = fgetc(fp1);
    char newline[2] = "\n";
    firstchar[0] = ch;
    int i = 1;
    while (ch != EOF)
    {
        if (ch == '\n')
        {
            firstchar[i] = fgetc (fp1);
            i++;
        }
        ch = fgetc(fp1);
    }
    fseek(fp1, 0, SEEK_END);
    fputs(newline, fp1);
    fputs(firstchar, fp1);
    fclose(fp1);
    return 0;
}