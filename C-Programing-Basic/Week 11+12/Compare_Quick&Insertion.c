#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InsertionSort (int Arr[],int n){
    int i,j,key;
    for (i = 1; i < n; i++) {
        key = Arr[i];
        j = i - 1;
        while (j >= 0 && Arr[j] > key)
        {
            Arr[j+1] = Arr[j];
            --j;
        }
        Arr[j+1] = key;
    }
}

void SWAP(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void QuickSort(int Arr[], int left, int right) {
    int i,j,pivot;
    if (left < right) 
    {
        do
        {
            i = left; j = right + 1; pivot = Arr[left];
            do {++i;} while (Arr[i] < pivot);
            do {--j;} while (Arr[j] > pivot);
            if (i < j ) SWAP(&Arr[i], &Arr[j]);
        } while (i < j);
    SWAP(&Arr[left], &Arr[j]);
    QuickSort(Arr, left, j - 1);
    QuickSort(Arr, j + 1, right);    
    }
    
}
int random (int minN, int maxN)
{
    return minN + rand() % (maxN + 1 * minN); 
}
void PrintList( int Arr[], int size)
{
    int i;
    for(i = 0; i < size; i++) printf("%d ", Arr[i]);
    printf("\n");
}
void copyArray(int arrDes[], int arrSrc[], int n){
    int i;
	for ( i = 0; i < n; i++){
        arrDes[i] = arrSrc[i];
    }
}
int main(){
    int n, i;
    srand(time(NULL));
    printf("Enter the number of radom number you want n = "); scanf("%d", &n);
    int Arr[n];
    for (i = 0; i < n; i++)
    {
    	Arr[i] = random (0, 10000);
	}
	
	//Time of QuickSort
	int *Arr1 = (int*) malloc(n * sizeof(int));
	copyArray(Arr1, Arr, n);
    clock_t beginQuicksort, endQuicksort;
    beginQuicksort = clock();
    QuickSort(Arr1, 0, n);
    PrintList(Arr1, n);
    endQuicksort = clock();
    int duration = (int) endQuicksort - beginQuicksort;
    printf("Time of Quicksort: %d (clocks)\n", duration );


	//Time of InsertionSort
	int *Arr2 = (int*) malloc(n * sizeof(int));
	copyArray(Arr2, Arr, n);
  	clock_t beginInsertion = clock();
    InsertionSort(Arr2, n);
    PrintList(Arr2, n);
    clock_t endInsertion = clock();
    int timeofInsertion = (int) endInsertion - beginInsertion;
    printf("Time of InsertionSort: %d (clocks)\n", timeofInsertion);
  	return 0;
}

