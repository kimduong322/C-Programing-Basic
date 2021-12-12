#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node_t {
    char Word[10];
    int count;
    struct node_t *left, *right;
} * Node;

int LeftOf (Node x, char *word)
{
    return strcmp (x->Word, word) < 0;
}
int RightOf (Node x, char *word) {
    return strcmp (x->Word, word) > 0;
}
void Insert (Node * root_ref, char * word)
{
    if (*root_ref == NULL)
    {   
        Node tmp = (Node) malloc (sizeof(struct node_t));
        strcpy (tmp->Word, word);
        tmp->count = 1;
        tmp->left = tmp->right = NULL;
        *root_ref = tmp;
    }
    else if (LeftOf(*root_ref, word)) Insert(&((*root_ref)->left), word);
    else if (RightOf(*root_ref, word)) Insert(&((*root_ref)->right), word);
}
Node Search (Node Root, char word[])
{
    if(Root == NULL) return NULL;
    if (strcmp(Root->Word, word) == 0) return Root;
    else if (LeftOf(Root, word) ) 
        return Search(Root->left, word);
    else if (RightOf(Root, word) )
        return Search(Root->right, word);  
}
void stringtolower (char word[])
{
    int i;
    for (i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);
        if (word[i] == '.') word[i] = '\0';      
    }
}
void countFeq (char filename[], Node *root_ref)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }
    char tmp[10];
    while (fscanf(f, "%s", tmp) != EOF) 
    {
        stringtolower(tmp);
        Node nodet = Search(*root_ref, tmp);
        if (nodet == NULL) Insert(root_ref, tmp);
        else ++nodet->count;
    }    
}
int FindWord (char wordtoFind[], Node Root)
{   
    Node node_tmp = Search(Root, wordtoFind);
    if (node_tmp == NULL) return 0;
    else return node_tmp->count;
}
void processFindWord (Node Root)
{
    printf("Enter a word you want to search: ");
    char wordtoFind[10];
    scanf("%s", wordtoFind);
    int occur = FindWord(wordtoFind, Root);
    printf("The word /%s/ has %d occur.\n", wordtoFind, occur);
}
int main()
{
    Node root = NULL;
    countFeq("WordCountInputFile.txt", &root);
    processFindWord(root);
    return 0;
}