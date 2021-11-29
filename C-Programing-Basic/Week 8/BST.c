#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int KeyType;
typedef struct NodeType_t {
    KeyType key;
    struct NodeType_t *left, *right;
} NodeType;

NodeType * CreateNode (KeyType data)
{
    NodeType * tmp = (NodeType *) malloc (sizeof (NodeType));
    tmp->key = data;
    tmp->left == NULL;
    tmp->right == NULL;
    return tmp;
}
void insertNodeToBST(KeyType x, NodeType * TreeRoot)
{
    if (TreeRoot == NULL) 
    {
    	TreeRoot = (NodeType *) malloc (sizeof (NodeType));
        TreeRoot->key = x;
        TreeRoot->left = NULL;
        TreeRoot->right = NULL;
    }
    else if(x < TreeRoot->key) insertNodeToBST(x, TreeRoot->left);
    else if(x > TreeRoot->key) insertNodeToBST(x, TreeRoot->right);
}

void PreOrder(NodeType * TreeRoot)
{
    if(TreeRoot != NULL)
    {
        printf("%d ", TreeRoot->key);
        PreOrder(TreeRoot->left);
        PreOrder(TreeRoot->right);
    }
}

void InOrder(NodeType * TreeRoot)
{
    if(TreeRoot != NULL)
    {
        InOrder(TreeRoot->left);
        printf("%d ", TreeRoot->key);
        InOrder(TreeRoot->right);
    }
}
void PostOrder(NodeType * TreeRoot)
{
    if(TreeRoot != NULL) {
        PostOrder(TreeRoot->left);
        PreOrder(TreeRoot->right);
        printf("%d ", TreeRoot->key);
    }
}
int Search(KeyType x, NodeType * TreeRoot) {
    if (TreeRoot == NULL) return 0;
    else if(TreeRoot->key = x) return 1;
    else if (x < TreeRoot-> key) Search(x, TreeRoot->left);
    else Search(x, TreeRoot->right);
}

int main()
{
    NodeType * TreeRoot = NULL;
    int i;
    for ( i = 0; i < 10; i++)
    {
        KeyType val = rand() % 100;
        printf("%d ", val);
        insertNodeToBST(val, TreeRoot);
    }
    
    if(Search(22, TreeRoot)) printf("22 ton tai trong cay.\n");
    else printf("22 KHONG ton tai trong cay.\n");

    printf("PreOrder: "); PreOrder(TreeRoot); printf("\n");
    printf("InOrder: "); InOrder(TreeRoot); printf("\n");
    printf("PostOrder: "); PostOrder(TreeRoot); printf("\n");

    return 0;
}
