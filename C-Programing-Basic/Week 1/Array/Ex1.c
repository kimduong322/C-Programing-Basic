#include<stdio.h>
#include<stdlib.h>

int main()
{
    double A[10];
    int i, min_near_value_index;
    printf("please enter 10 numbers: \n");
    for ( i = 0; i < 10; i++)
    {
        scanf("%lf", &A[i]);
    }
    
    printf("numbers in reversed order: \n");
    for ( i = 9; i >= 0; i--)
    {
        printf("%3.4f	", A[i]);
    }

    printf("\n");
    
    double s=0.0;
    for (  i = 0; i < 10; i++)
    {
        s = s + A[i];
    }
     double avg = s/10;
     double min_near_value = fabs(avg - A[0]);
    for (  i = 0; i < 9; i++)
    {
        if (fabs(avg - A[i]) < min_near_value)
        {
            min_near_value = fabs(avg - A[i]);
            min_near_value_index = i;
        }
    
    }
    
    printf("Phan tu co gia tri gan nhat voi gia tri trung binh la: %3.4f", A[min_near_value_index]);

    return 0;
}
