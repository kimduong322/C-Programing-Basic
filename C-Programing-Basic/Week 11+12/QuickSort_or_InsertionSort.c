#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ADD (100)
typedef struct pAddress_t {
    char Name[50];
    char Phone[12];
    char Email[50];
} pAddress;

void SWAP(pAddress *list1, pAddress *list2) {
    pAddress temp;
    strcpy(temp.Name, list1->Name); strcpy(temp.Phone, list1->Phone); strcpy(temp.Email, list1->Email);
    strcpy(list1->Name, list2->Name); strcpy(list1->Phone, list2->Phone); strcpy(list1->Email, list2->Email);
    strcpy(list2->Name, temp.Name); strcpy(list2->Phone, temp.Phone); strcpy(list2->Email, temp.Email);
}

void SortByName_UseQuickSort(pAddress list[], int left, int right) {
    if(left < right) {
	    int i = left, j = right + 1; 
	    char pivot[50];
	    strcpy(pivot, list[left].Name);
	    do
	    {
	        do {
			++i;
			} while (strcmp(pivot, list[i].Name) < 0);  
	        do {
			--j;
			} while (strcmp(pivot, list[j].Name) > 0);
	        if(i < j) SWAP(&list[i], &list[j]);
	    } while (i < j);
	    SWAP(&list[left], &list[j]);
	    SortByName_UseQuickSort(list, left, j - 1);
	    SortByName_UseQuickSort(list, j + 1, right);
		}
	    
}

void InsertionSort (pAddress list[], int size) 
{
    int i, j; pAddress key;
    for(i = 1; i < size; i++) {
        strcpy(key.Name,list[i].Name); strcpy(key.Phone, list[i].Phone); strcpy(key.Email, list[i].Email);
        j = i - 1;
        while (j >= 0 && strcmp(list[j].Name,key.Name) > 0) 
        {
            strcpy(list[j+1].Name,list[j].Name); 
            strcpy(list[j+1].Phone, list[j].Phone);
            strcpy(list[j+1].Email, list[j].Email);
            --j;
        }
        strcpy(list[j+1].Name, key.Name); strcpy(list[j+1].Phone, key.Phone); 
        strcpy(list[j+1].Email, key.Email);       
    }
}

void SortProcess(int x, int n, pAddress list[]) {   
    if(n < x) InsertionSort(list, n);
    else SortByName_UseQuickSort(list, 0, n);
}

void printList( pAddress list[], int size)
{
	int i; 
	printf("%50s %12s %50s\n", "Name", "Phone", "Email");
	for(i = 0; i < size; i++)
	{
		printf("%50s %12s %50s\n", list[i].Name, list[i].Phone, list[i].Email);
	}
}
int main() {
    int i, x;
    pAddress list[100];
    FILE * f = fopen ("data.txt", "r");
    for(i = 0; i < 10; i++)
    {
        fscanf(f, "%s %s %s\n", list[i].Name, list[i].Phone, list[i].Email);
    }
    printf("x = "); scanf("%d", &x);
    SortProcess(x, 10, list);
    printList(list, 10);
    fclose(f);   
}
