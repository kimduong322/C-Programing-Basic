#include <stdio.h>
#include <stdlib.h>

typedef int elmtType;

typedef struct NodeType_t {
     elmtType element;
     struct NodeType_t * left, * right; 
} NodeType;

NodeType * CreateNode(elmtType data)
{
    NodeType * tmp = (NodeType*)malloc(sizeof(NodeType));
    if (tmp != NULL)
    {
        tmp->element = data;
        tmp->left = NULL;
        tmp->right = NULL;
    }
    
    return tmp;
}

int EmptyTree (NodeType * head)
{
    return head == NULL;
}

NodeType * RightChild (NodeType * cur)
{
    if (cur != NULL)
    {
        return cur->right;
    }
    else return NULL;
}

NodeType * LeftChild (NodeType * cur)
{
    if (cur != NULL) return cur->left;
    else return NULL;
}

int isLeaf (NodeType* cur){
    return (RightChild(cur) == NULL) && (LeftChild(cur) == NULL);
}
int max(int a, int b){
    return (a > b) ? a : b;
}

int Height (NodeType * TreeRoot) {
    int HeightLeft, HeightRight, HeightValue;
    NodeType* cur = TreeRoot;
    if (cur == NULL) HeightValue = -1;
    else
    {
        HeightLeft = Height(cur->left);
        HeightRight = Height(cur->right);
        HeightValue = 1 + max(HeightLeft, HeightRight);
    }
    return HeightValue;
}

int CountLeaf (NodeType * TreeRoot)
{
    if (TreeRoot == NULL) return 0;
    else
    {
        int count = 0;
        count += CountLeaf(TreeRoot->left);
        count += CountLeaf(TreeRoot->right);
        if (TreeRoot->left == NULL && TreeRoot->right == NULL)
        {
            ++count;
        }
    return count;    
    }
    
}
int TreeSize(NodeType * TreeRoot)
{
    int count;
    if(TreeRoot == NULL) count = 0;
    else
    {
        count = 1 + TreeSize(TreeRoot->left) + TreeSize(TreeRoot->right);     
    }
    return count;
}

int CountInternalNodes(NodeType * TreeRoot)
{
    return TreeSize(TreeRoot) - CountLeaf(TreeRoot);
}

int CountRightChild(NodeType * TreeRoot)
{
    if (TreeRoot == NULL) return 0;
    else return 1 + CountRightChild(TreeRoot->right);
}
int main()
{
    /*
     8
    / \
   10  9
   /\  /\
  1  2 3 4
    */
   int choice ;
   NodeType *TreeRoot = CreateNode(8);
   TreeRoot->left = CreateNode(10);
   TreeRoot->right = CreateNode(9);
   TreeRoot->left->left = CreateNode(1);
   TreeRoot->left->right = CreateNode(2);
   TreeRoot->right->left = CreateNode(3);
   TreeRoot->right->right = CreateNode(4);
   printf("MENU\n1.Height of a binary tree\n2.Number of leaves\n3.Number of internal nodes\n4.Number of right children\n5.Exit\n");
   printf("--------------------------------\nChoice = "); scanf("%d", &choice);
   while(choice >= 1 && choice <= 5)
   {
       if(choice == 1 ) printf("Height of Tree: %d\n", Height(TreeRoot));
       if(choice == 2 ) printf("Number of leaves: %d\n", CountLeaf(TreeRoot));
       if (choice == 3 ) printf("Number of internal nodes: %d\n", CountInternalNodes(TreeRoot));
       if (choice == 4 ) printf("Number of right children: %d\n", CountRightChild(TreeRoot));
       if (choice == 5 )
       {
           printf("See you again !! ");
           break;
       }
       printf("Choice = "); scanf("%d", &choice);
   }
   return 0;
}
