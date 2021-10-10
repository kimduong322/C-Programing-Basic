#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(/*int argc, char *argv[]*/)
{
    /*if (argc != 2)
    {
        printf("\n%s%s\n\n%s%s\n\n","Usage:  ", argv[1], "  infile  ",
        "The contents of infile will be double-spaced ",
        "and written return to infile.");
        exit(-1);
    }*/
    
    FILE *fp1, *fp2;
    fp1 = fopen(/*argv[1]*/"data_insert_SpLine.txt", "r");
    if(fp1 == NULL) {
	printf("cannot open file data_insert_SpLine.txt !");
	exit(-1);
	}
    
	fp2 = fopen("temp.txt", "w+");
    if(fp2 == NULL) {
	printf("cannot open file temp.txt !");
	exit(-2);
	}
    char c = fgetc(fp1);
    while (c != EOF)
    {
        fputc(c, fp2);
        if (c == '\n') fputc('\n', fp2);
    }
    fclose(fp1);
    fclose(fp2);
    remove("data_insert_SpLine.txt");
    rename("temp.txt", "data_insert_SpLine.txt");
    return 0;
}
