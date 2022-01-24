#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pAdd_t {
    char name[50];
    char phone[12];
    char email[50];
} pAddRec;

void LoadFile(char* filename, pAddRec list[])
{
    int i; 
    FILE* fp = fopen(filename, "r");
    if (fp ==  NULL) printf("Cannot open file !\n");
    for (i = 0; i < 10; i++) {
        fscanf(fp, "%s %s %s\n",list[i].name, list[i].phone, list[i].email);
        if(feof(fp)) break;
    }
    fclose(fp);
}

// Dùng để sắp xếp mảng bằng thuật toán sắp xếp chèn
void insertSortArr(pAddRec list[], int n)
{
    int i, j;

    pAddRec next;

    for (i = 1; i < n; i++)
    {
        // next = list[i]
        strcpy(next.email, list[i].email); 
        strcpy(next.name, list[i].name);
        strcpy(next.phone, list[i].phone);

        for (j = i-1; j >= 0 && strcmp(next.name, list[j].name) < 0; j--)  
        {
            strcpy(list[j+1].name, list[j].name);
            strcpy(list[j+1].email, list[j].email);
            strcpy(list[j+1].phone, list[j].phone);
        }
        strcpy(list[j+1].name, next.name);
        strcpy(list[j+1].email, next.email);
        strcpy(list[j+1].phone, next.phone);
    }
    
}

void selectSortArr(pAddRec list[], int n)
{
    int i, j, min;
    pAddRec tmp;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        
        // find index of min of list[i+1..n-1]
        for (j = i+1; j <= n - 1; j++)
        {
            if(strcmp(list[j].name, list[min].name) < 0)    
                min = j;
        }
        
        // tmp = list[i]
        strcpy(tmp.email, list[i].email); strcpy(tmp.name, list[i].name); strcpy(tmp.phone, list[i].phone);
        // list[i] = list[min]
        strcpy(list[i].email, list[min].email); strcpy(list[i].name, list[min].name); strcpy(list[i].phone, list[min].phone);
        // list[min] = tmp
        strcpy(list[min].email, tmp.email); strcpy(list[min].name, tmp.name); strcpy(list[min].phone, tmp.phone);
    }
    
}

void Export(char * filename, pAddRec list[]) 
{
    FILE * fp = fopen(filename, "w");
    if (fp == NULL)         
    {
        printf("Cannot open file %s!\n", filename);
        exit(-1);
    }
    
    for (int i = 0; i < 10; i++)
    {
        fprintf(fp, "%s %s %s\n", list[i].name, list[i].phone, list[i].phone);
    }
    
    fclose(fp);
}


// Single Linked List
typedef struct pAdd_linkedlist
{
    pAddRec data;

    struct pAdd_linkedlist * next;
} node;

node * makenew(pAddRec a)
{
    node * tmp = (node*)malloc(sizeof(node));
    if (tmp == NULL)
        printf("Cannot memory allocation!\n");
    strcpy(tmp->data.email, a.email);
    strcpy(tmp->data.name, a.name);
    strcpy(tmp->data.phone, a.phone);
    tmp->next = NULL;
     return tmp;
}

// Function to sort a linked list using selection
// sort algorithm by swapping the next pointers
node* selectionSort(node* head)
{
    node *a, *b, *c, *d, *r;
 
    a = b = head;
 
    // While b is not the last node
    while (b->next) {
 
        c = d = b->next;
 
        // While d is pointing to a valid node
        while (d) {
 
            if (strcmp(b->data.name, d->data.name) > 0) {
 
                // If d appears immediately after b
                if (b->next == d) {
 
                    // Case 1: b is the head of the linked list
                    if (b == head) {
 
                        // Move d before b
                        b->next = d->next;
                        d->next = b;
 
                        // Swap b and d pointers
                        r = b;
                        b = d;
                        d = r;
 
                        c = d;
 
                        // Update the head
                        head = b;
 
                        // Skip to the next element
                        // as it is already in order
                        d = d->next;
                    }
 
                    // Case 2: b is not the head of the linked list
                    else {
 
                        // Move d before b
                        b->next = d->next;
                        d->next = b;
                        a->next = d;
 
                        // Swap b and d pointers
                        r = b;
                        b = d;
                        d = r;
 
                        c = d;
 
                        // Skip to the next element
                        // as it is already in order
                        d = d->next;
                    }
                }
 
                // If b and d have some non-zero
                // number of nodes in between them
                else {
 
                    // Case 3: b is the head of the linked list
                    if (b == head) {
 
                        // Swap b->next and d->next
                        r = b->next;
                        b->next = d->next;
                        d->next = r;
                        c->next = b;
 
                        // Swap b and d pointers
                        r = b;
                        b = d;
                        d = r;
 
                        c = d;
 
                        // Skip to the next element
                        // as it is already in order
                        d = d->next;
 
                        // Update the head
                        head = b;
                    }
 
                    // Case 4: b is not the head of the linked list
                    else {
 
                        // Swap b->next and d->next
                        r = b->next;
                        b->next = d->next;
                        d->next = r;
                        c->next = b;
                        a->next = d;
 
                        // Swap b and d pointers
                        r = b;
                        b = d;
                        d = r;
 
                        c = d;
 
                        // Skip to the next element
                        // as it is already in order
                        d = d->next;
                    }
                }
            }
            else {
 
                // Update c and skip to the next element
                // as it is already in order
                c = d;
                d = d->next;
            }
        }
 
        a = b;
        b = b->next;
    }
 
    return head;
}
