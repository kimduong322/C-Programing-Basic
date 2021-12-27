#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ADD (100)
typedef struct pAddress_t {
    char Name[50];
    char Phone[12];
    char Email[50];
} pAddress;
 
// Hàm LoadFile(char * filename, pAddress list[]) đọc danh sách 10 bạn từ filename và lưu vào mảng list[]
void LoadFile(char * filename, pAddress list[])
{
	int i;
    FILE * f = fopen(filename, "r");
    if (f == NULL) printf("Error: Cannot open file %s\n", filename);
    for ( i = 0; i < 10; i++)
    {
        fscanf(f, "%s %s %s\n", list[i].Name, list[i].Phone, list[i].Email);
    }
    fclose(f);
}
// Hàm SWAP(pAddress *list1, pAddress *list2) đổi chỗ 2 phần tử trong danh sách list
void SWAP(pAddress *list1, pAddress *list2) {
    pAddress temp;
    strcpy(temp.Name, list1->Name); strcpy(temp.Phone, list1->Phone); strcpy(temp.Email, list1->Email);
    strcpy(list1->Name, list2->Name); strcpy(list1->Phone, list2->Phone); strcpy(list1->Email, list2->Email);
    strcpy(list2->Name, temp.Name); strcpy(list2->Phone, temp.Phone); strcpy(list2->Email, temp.Email);
}
//Hàm SortByName_UseQuickSort(pAddress list[], int 0, int 10) sẽ sắp xếp list[] theo thứ tự tăng dần trong bảng chữ cái theo tên bằng sắp xếp nhanh
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
void Export2File(pAddress list[], char *filename)
{
	int i;
    FILE * fp = fopen(filename, "w+");
    if (fp == NULL) printf("Error: Cannot open file %s", filename);
    for ( i = 0; i < 10; i++) {
        fprintf(fp, "%s %s %s\n", list[i].Name, list[i].Phone, list[i].Email);
    }
    fclose(fp);
}
int main() {
    pAddress list[MAX_ADD];
    LoadFile("data.txt", list);
    SortByName_UseQuickSort(list, 0, 9);
    Export2File(list, "Output.txt");
}
