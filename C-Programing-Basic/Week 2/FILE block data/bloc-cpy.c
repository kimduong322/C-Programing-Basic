#include <stdio.h>
enum {SUCESS, FALL, MAX_LEN = 80};


void BlockReadFile(FILE *fin, FILE *fout){
    char buf[MAX_LEN + 1];
    int num;
    while (!feof(fin))
    {
        num = fread(buf, sizeof(char), MAX_LEN, fin);
        buf[num * sizeof(char) ] = '\0';
        printf("%s", buf);
        fwrite(buf, sizeof(char), num, fout);
    }
    
}
int main(int argc, char *argv[])
{
    if (argc < 3)   
    {
        printf("%s <file_in> <file_out>\n", argv[0]);
    }
    
    FILE *fp1, *fp2;
    int reval = SUCESS;
    if ((fp1 = fopen(argv[2], "w+")) == NULL)
    {
        printf("Error: Cannot open file %s", argv[2]);
        reval = FALL;
    }
    else if ((fp2 = fopen(argc[1], "r")) == NULL)
    {
        printf("Error: Cannot open file %s", argv[1]);
        reval = FALL;
    }
    else
    {
        BlockReadFile(fp2, fp1);
        fclose(fp1);
        fclose(fp2);
    }
 return 0  ;    
}

