#include <stdio.h>
#include <string.h>

int notFound = -1;
int Count = 0;
enum {SUCESS, FFAIL, MAX_ELEMENT = 100};

typedef struct pAddress{
    char name[20];
    char tell[13];
    char email[50];
} phoneAddress;

phoneAddress List[MAX_ELEMENT];

void ReadFile(char *filename)
{
    FILE * fp = fopen(filename, "r"); 
    int i = 0;
    
	if ( fp == NULL ) printf("Cannot open file %s\n", filename);
    
    while(!feof(fp))
    {
        fscanf(fp, "%s\n%s\n%s\n", List[i].name, List[i].tell, List[i].email);
        ++i;
        if (i > MAX_ELEMENT) break;
        Count = i;
    }
    fclose(fp);
}

int BinSearch(phoneAddress A[], char * name, int N)
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
    int index = BinSearch(List, target, Count );
    if (index == -1) fprintf (fp, "Cannot find the information of this contact!\n");
    else 
    fprintf(fp, "%s\n%s\n%s\n", List[index].name, List[index].tell, List[index].email);
    fclose(fp);
}

int main()
{
    char target[50];
    ReadFile("ContactList.txt");
    printf("Please know me the name of contact you want search: ");
    scanf("%s", &target);
    PrintResultToFile("ContactList_Output.txt", target);
    return 0;
}
