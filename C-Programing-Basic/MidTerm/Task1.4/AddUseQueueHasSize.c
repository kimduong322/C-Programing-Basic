#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SiZE_QUEUE (10)
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

void DeQueue ()
{
    if (!EmptyQueue())
    {
        Address * tmp = queue_front;
        queue_front = queue_front->next;
        free(tmp);
    }
    else printf("Cannot dequeue because queue is empty !");
}

int isQueueFull () {
    int count = 0;
    Address * tmp =  queue_front;
    if (tmp == NULL) return 0;
    else {
        count = 1;
        for (tmp; tmp != NULL; tmp = tmp->next) ++count;
    }
    return count == MAX_SiZE_QUEUE;
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
        if (!isQueueFull()) EnQueue(name, numb, email);
        else {
            printf("%s %s %s\n", queue_front->Name, queue_front->PhoneNumb, queue_front->Email);
            DeQueue ();
            EnQueue(name, numb, email);
        }
        
    }
    fclose(fp);
}

int main () {
    ReadFile("Input.txt");
    return 0;
}