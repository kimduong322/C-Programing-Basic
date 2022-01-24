#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int notFound = -1;
enum {SUCESS, FAIL, MAX_ELEMENT = 100};

typedef struct pAddress{
    char name[255];
    char tell[13];
    char email[50];
} Address;

Address List[MAX_ELEMENT];

void ReadFile(char *filename)
{
    FILE * fp = fopen(filename, "r"); 
    int i ;
    
	if ( fp == NULL ) printf("Cannot open file %s\n", filename);
    for ( i = 0; i < 10; i++)
    {
        fflush(stdin);
        fscanf(fp, "%s %s %s\n", List[i].name, List[i].tell, List[i].email);
    }
    fclose(fp);
}
void Sort(){
    int i,j ;
    for ( i = 0; i < 10; i++)
    {
        for ( j = i; j < 10; j++)
        {
            if (strcmp (List[i].name,List[j].name) < 0)
            {
                Address tmp;
                strcpy(tmp.name, List[i].name); strcpy (tmp.email, List[i].email); strcpy(tmp.tell, List[i].tell);
                strcpy(List[i].name, List[j].name); strcpy (List[i].email, List[j].email); strcpy(List[i].tell, List[j].tell);
                strcpy(List[j].name, tmp.name); strcpy (List[j].email, tmp.email); strcpy(List[j].tell, tmp.tell);
            }
            
        }
        
    }
    
}
int BinSearch(Address A[], char * name, int N)
{
    int Lo = 0,
        Hi = N - 1,
        mid;
    while (Lo <= Hi) 
    {
        mid = (Lo + Hi) / 2;
        if ( strcmp(A[mid].name, name) < 0 ) Lo = mid + 1;
        else if ( strcmp(A[mid].name, name) > 0 ) Hi = mid - 1;
        else return mid;
    }
    return notFound;
}

void PrintResultToFile(char *filename, char* target)
{
    FILE * fp = fopen(filename, "w+");
    if ( fp == NULL ) printf("Cannot open file %s\n", filename);
    int index = BinSearch(List, target, 11);
    if (index == -1) fprintf (fp, "Cannot find the information of this contact!\n");
    else fprintf(fp, "%s %s %s\n", List[index].name, List[index].tell, List[index].email);
    fclose(fp);
}
int main( )
{
    char target[50];
    ReadFile("Input.txt");
    
    int i;
    printf("After Sort:\n");
    for ( i = 0; i < 10; i++)
    {
        printf("%s %s %s\n", List[i].name, List[i].tell, List[i].email);
    }
    printf("Please know me the name of contact you want search: ");
    scanf("%s", &target);
    PrintResultToFile("OutputFile.txt", target);
    return 0;
}
