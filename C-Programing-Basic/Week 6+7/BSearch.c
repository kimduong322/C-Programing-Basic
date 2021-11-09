#include <stdio.h>
#define notFound -1
int count = 1;

int binSearch(int A[], int target, int size)
{   
    count = 1;
    int Lo = 0, 
        Hi = size - 1,
        mid;
    while (Lo <= Hi) 
    {
        mid = (Lo + Hi) / 2;
        ++count;
        if (target == mid) 
        {
            return mid;
        }
        else if (target > mid) Lo = mid + 1;
        else if (target < mid) Hi = mid - 1;
    }
    return notFound;
}

int main() {
    int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int size = sizeof(A)/sizeof(A[0]);
    int i;
    for ( i = 0; i < 20; i++)
    {
        printf("BinarySearch of %d in Array is %d\n", i, binSearch(A, i, size));
        printf("Numbers of comparisons are %d. \n\n", count);
    }
    return 0;
}
