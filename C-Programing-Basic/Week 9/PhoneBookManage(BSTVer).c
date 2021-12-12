#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX (10)
typedef struct {
    char Name[50];
    char PhoneNumb[12];
    char email[50];
} Item;

Item phoneAdd[MAX];

typedef struct Node {
    Item data;
    struct tree_t * left, * right;
} * BST ;

void loadFile(char * filename, Item phoneAdd[])
{
    FILE * fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Cannot open file!");
        exit(-1);
    }
    while (! feof(fp))
    {
        int i = 0 ;
        fscanf(fp, "%s %s %s\n", phoneAdd[i].Name, phoneAdd[i].PhoneNumb, phoneAdd[i].email);
        ++i;
    }
    fclose(fp);
}

int Insert (Item x, BST * root_ref) {
    if (*root_ref == NULL)
    {
    	BST tmp = (BST)malloc(sizeof(BST));
        tmp->data = x;
        tmp->left = tmp->right = NULL;
        *root_ref = tmp ;
    }
    else if (strcmp (x.email,((*root_ref)->data).email ) < 0) Insert (x, (*root_ref)->left);
    else if (strcmp (x.email,((*root_ref)->data).email) > 0) Insert (x, (*root_ref)->right);
    else if (strcmp (x.email,((*root_ref)->data).email) == 0 ) return -1; //PhoneBook existed !

    return 1;
}

void Out (Item x)
{
    printf ("%50s %12s %50s\n", x.Name, x.PhoneNumb, x.email);
}

void InOrder (BST * root_ref)
{
    if (*root_ref != NULL) {
        InOrder(&(*root_ref)->left);
        Out((*root_ref)->data);
        InOrder((*root_ref)->right);
    }
}

void CreateBST (Item A[], BST *root_ref) {
    int i;
    for ( i = 0; i < MAX, ++i;) {
        int  check;
        check = Insert (A[i], root_ref);
        if (check == 0) printf("Memories Allocation Failed ! Memories Full!\n");
        if (check == -1) printf("PhoneBook existed ! Can not insert !\n");
    }
}

int main () {
    loadFile("Input.txt", phoneAdd);
    BST root = NULL;
    CreateBST (phoneAdd, &root);
    return 0;
}
