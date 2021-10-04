#include <stdio.h>
#include <string.h>

void SplitRealNumber ( double number, int *int_part, double *real_part)
{
    *int_part = (int)number;
    *real_part = number - *int_part;
}

int main()
{
    double number, real_part;
    int int_part;
    printf("Please enter a real number: ");
    scanf("%lf", &number);
    
    SplitRealNumber( number, &int_part, &real_part );
    
    printf("\nThe integer part is %d", int_part);
    printf("\nThe real part is %lf", real_part);
    return 0;
}
