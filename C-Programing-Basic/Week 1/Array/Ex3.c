#include <string.h>
#include <stdio.h>

#define SIZE 6


int checkArrSame(int A1[], int A2[], int size)
{
    int checknum = 1, i = 0;
    for ( i = 0; i < size; i++)
    {
        if (A1[i] != A2[i])
       {
            checknum = 0;
            break;
        }       
    }
    return checknum;
}

int checkArrSymetric(int A1[], int A2[], int size)
{
    int checknum = -1, i;
    for (i = 0; i < size; i++)
    {
        if (A1[i] != A2[i])
        {
            checknum = 0;
            break;
        }
    }
    return checknum;
}


int main()
{
    int input1[SIZE], input2[SIZE], i;
    printf("please enter %d numbers of list1: \n", SIZE);
    for ( i = 0; i < SIZE; i++)
    {
        scanf("%d", &input1[i]);
    }
    printf("please enter %d numbers of list2: \n", SIZE);
    for ( i = 0; i < SIZE; i++)
    {
        scanf("%d", &input2[i]);
    }
    if (checkArrSame( input1, input2, SIZE) == 1)
    {
        printf("Hai mang trung nhau!\n");
    }
    else printf("Hai mang KHONG trung nhau!\n");
    if (checkArrSymetric(input1, input2, SIZE) == -1)
    {
        printf("Hai mang doi xung!\n");
    }
    else printf("Hai mang KHONG doi xung!\n");

   return 0; 
}