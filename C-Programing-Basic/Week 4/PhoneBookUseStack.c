#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phoneBook {
    char Name[50];
    char PhoneNumb[12];
    char email[50];
    
    struct phoneBook *next;
} phoneBook;

phoneBook * root = NULL;

phoneBook* MakePhone(char *name, char* numb, char* email)
{
    phoneBook *tmp = (phoneBook*)malloc(sizeof(phoneBook));
    strcpy(tmp->Name, name);
    strcpy(tmp->PhoneNumb, numb);
    strcpy(tmp->email, email);

    tmp->next = NULL;
    return tmp;
}

phoneBook* push(char *name, char* numb, char* email)
{
    if (root == NULL)
    {
        root = MakePhone(name, numb, email);
    }
    else
    {
        phoneBook * tmp = MakePhone(name, numb, email);
        tmp->next = root;
        root = tmp;
    }
    return root;
}

phoneBook* ReadFile(char *FileName)
{
    FILE* fp;
    fp =  fopen(FileName, "r");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", FileName);
    }
    char name[51], numb[12], email[51];
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s\n", name, numb, email);
        push(name, numb, email);
    }
    fclose(fp);
    return root;
}

void WriteToFile(char *filename)
{
    FILE* fp;
    fp =  fopen(filename, "w+");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", filename);
    }
    
    phoneBook* cur = root;
    for ( cur ; cur != NULL; cur = cur->next)
    {
        fprintf(fp, "%s %s %s\n", cur->Name, cur->PhoneNumb, cur->email);
    }
    fclose(fp);
}

int main(){
    ReadFile("PhoneB_List.txt");
    //printf("%s", root->Name);
    WriteToFile("PhoneB_Out.txt");

    return 0;
}
