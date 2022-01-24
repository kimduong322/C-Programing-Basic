#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct AddressUseQueue_t
{
    char Name[50];
    char PhoneNumb[12];
    char Email[50];

    struct AddressUseQueue_t * next;
}   Address;

Address * queue_front = NULL, *queue_rear = NULL;

Address* CreateNode (char* name, char* numb, char* email)
{
    Address* tmp = (Address*)malloc(sizeof(Address));
    strcpy(tmp->Name, name);
    strcpy(tmp->PhoneNumb, numb);
    strcpy(tmp->Email, email);
    tmp->next = NULL;
    return tmp;
}

int EmptyQueue ()
{
    return (queue_front == NULL && queue_rear == NULL);
}

void EnQueue (char * name, char* numb, char* email)
{
    Address* tmp = CreateNode (name, numb, email);
	if (EmptyQueue())
    {
        queue_front = tmp;
        queue_rear = tmp;
    }
    else{
        queue_rear->next = tmp;
        queue_rear = tmp;
    }
}


void ReadFile ( char* filename)
{
    FILE* fp = fopen(filename, "r" );
    char name[50], numb[12], email[50];
    if (fp == NULL)
    {
        printf("Cannot open file %s", filename);
    }
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s", name, numb, email);
        EnQueue(name, numb, email);
    }
    fclose(fp);
}

void Search (char * name, char *filename)
{
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        printf("Can not open file ! \n");
        exit(1);
    }
    
    Address * tmp;
    for (tmp  = queue_front;  tmp != NULL; tmp = tmp->next)
    {
        if (strcmp (tmp->Name, name) == 0)
        fprintf(fp, "%s %s %s\n", tmp->Name, tmp->PhoneNumb, tmp->Email);
    }
    fclose(fp);
}


int main() 
{
    ReadFile("Input.txt");
    Search("NguyenVanThienAnh", "Output.txt");
    return 0;
}
