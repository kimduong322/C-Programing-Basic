#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    FILE *fp1, *fp2;
    fp1 = fopen("lab1.txt", "r");
    fp2 = fopen("lab1w.txt", "w");
	char c = fgetc(fp1);   
	printf("%c", c);
   do
   {
        if (isupper(c))
        {
            fputc(tolower(c), fp2);
            c = fgetc(fp1);
        }
        else if (islower(c))
		{
            fputc(toupper(c), fp2);
            c = fgetc(fp1);
        }
        else{
            fputc(c,fp2);
            c = fgetc(fp1);
        }
   } while ( c  != EOF);
   
    fclose(fp1);
    fclose(fp2);
    return 0;
}
