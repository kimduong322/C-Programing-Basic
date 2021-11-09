#include <stdio.h>
#define notFound -1

int BinarySearchRecursive(int A[], int Lo, int Hi, int target)
{
    if(Lo > Hi) return notFound;
    int mid = (Lo + Hi) / 2;
    if (target < A[mid])
    return BinarySearchRecursive(A, Lo, mid - 1, target);
    else if (target > A[mid])
    return BinarySearchRecursive(A, mid + 1, Hi, target);    
    else return mid;
    
    return notFound;
}

int main()
{
    int target;
    int position;
    int A[] = {1, 3, 5, 9, 11, 13, 15, 17};
    printf("Search for: ");
    scanf("%d", &target);
    position = BinarySearchRecursive(A, 0, sizeof(A)/sizeof(A[0]), target);
    if (position == -1 )
    {
        printf("Cannot find target in Array\n");
    }
    else
    {
        printf("The position of the target is %d.\n", position +1 );
    }
    return 0;
}
