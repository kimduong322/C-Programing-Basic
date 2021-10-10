#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {SUCESS, FAIL};

int main(void) {
    FILE *fp;
    int *p;
    int i, n, value, sum;
    int reval = SUCESS;

    printf("Enter a list of numbers with the first is the size of list: \n");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int)); sum = 0 ;
    for(i = 0; i< n; i++ ) {
        scanf("%d", &p[i]);
        
        sum += p[i];
    }
    if ((fp = fopen("out.txt", "w")) == NULL) {
        printf("Cannot open file %s\n", "out.txt");
        reval = FAIL;
    }


    for ( i = n -1 ; i >= 0; i--)
    {
        fprintf(fp, "%d ", p[i]);

    }
    fprintf(fp, "%d", sum);
    fclose(fp);
    free(p);
    return reval;
    
}
