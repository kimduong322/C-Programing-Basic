#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ADD (100)
typedef struct pAddress_t {
    char Name[50];
    char Phone[12];
    char Email[50];

    struct pAddress_t *next;
} pAddress;
//prototypes function
pAddress * SortedMerge(pAddress *a, pAddress *b) ;
void frontBackSplit(pAddress * source, pAddress ** frontRef, pAddress ** backRef);
//
void MergeSort ( pAddress ** headRef)
{
    pAddress *a, *b;
	pAddress * head = *headRef;
    if((head) == NULL || ((head)->next == NULL)) return;

    frontBackSplit(head, &a, &b);

    MergeSort (&a);
    MergeSort (&b);

    *headRef = SortedMerge (a, b);
}

void frontBackSplit(pAddress * source, pAddress ** frontRef, pAddress ** backRef) {
    pAddress *slow, *fast;
    slow = source;
    fast = source->next;
    while (fast != NULL) 
    {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
			fast = fast->next;
        }
    }
    
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

pAddress * SortedMerge(pAddress *a, pAddress *b) {
    pAddress * result;
    if (a == NULL) return b;
    if (b == NULL) return a;
    if (strcmp(a->Name, b->Name) < 0 )
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

void Push (pAddress ** head_ref, char * Name, char * Phone, char * Email) {
    pAddress * tmp = (pAddress*)malloc(sizeof(pAddress));
    strcpy(tmp->Name, Name); strcpy(tmp->Phone, Phone); strcpy(tmp->Email, Email); tmp->next = NULL;
    tmp->next = *head_ref;
    *head_ref = tmp;
}
// Read data from data.txt and push into singly linked list
void LoadFile(char* filename, pAddress **head)
{
    int i; char Name[50], Phone[12], Email[50];
    FILE* fp = fopen(filename, "r");
    if (fp ==  NULL) printf("Cannot open file !\n");
    for ( i = 0; i < 10; i++) {
        fscanf(fp, "%s %s %s\n", Name, Phone, Email);
        Push(head, Name, Phone, Email);
        if(feof(fp)) break;
    }
    fclose(fp);
}

void printList(pAddress *head) {
	int i;
    printf("%50s %12s %50s\n", "Name", "Phone", "Email");
    for (i = 0; i < 10; i++)
    {
        printf("%50s %12s %50s\n", head->Name, head->Phone, head->Email);
        head =head->next;
    }
    
}

int main() {
    pAddress *head = NULL;
    LoadFile("data.txt", &head);
	printList(head);
    MergeSort(&head);
    printList(head);
    return 0;
}
