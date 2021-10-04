#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(/*int argc, char *argv[]*/)
{
  /*  if (argc != 2)
    {
        printf("Wrong !\n");
        printf("Usage format: <printnumberline> <filename>");
    }
   */ 

    FILE *fp1, *fp2;
    int count = 0, i = 1;
    fp1 = fopen("lab1.txt", "r");
    if (fp1 == NULL) 
    {
        printf("Cannot open file !");
        return -1;
    }
    rewind(fp1);

    char StrTmp[1000], space[2] = " ";
    char num[2];
    while(fgets(StrTmp, 10000, fp1)) {
        ++count;
    }
	printf("%d lines", count);
    fp2 = fopen("temp.txt", "w+");
    if (fp2 == NULL)
    {
        printf("can open file temp.txt");
        return -2;
    }
    char arr[count][100000];
    for ( i = 0; i < count; i++)
    {
        fflush(stdin);
        fgets(arr[i], 100000, fp1);
    }
    char numb[count][3] ;
    for ( i = 0; i < count; i++)
    {
        numb[i][0] = i;
        numb[i][1] = ' ';
    }
    for ( i = 0; i < count; i++)
    {
        fputs(numb[i], fp2);
        fputs(arr[i], fp2);
    }
    
    
    fclose(fp1);
    fclose(fp2);
    remove("lab1.txt");
    rename("temp.txt", "lab1.txt");
    return 0;
}
