#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct node_t {
    char email[50];   //key 
    char name[50];
    char phone[12];
    
    struct node_t * next;
} node;

typedef struct htNode_t
{
    int key;

    struct node_t * next;
} htNode;

htNode hastTable[TABLE_SIZE];

int _chartoInt (char c) {
    int num = c - '0';
    return num;
}

/* Bản đồ mã băm (hascodeMap) */
long int hashcodeMap(char email[]) // keyType: email address
{   
    int numofchar;
    int z = 33;
    int Pz;  // Pz = Tổng(a_{i}*z^i, i={0..n-1})
    for (int i = 0; i < strlen(email); i++)
    {
        char c = email[i];
        numofchar = _chartoInt(c);
        Pz += numofchar * z^i;
    }
    return Pz;
}

/* Sơ đồ nén */
int compressionMap(long int hashcode) {
    return hashcode % TABLE_SIZE;
}

/* Hàm băm HashFunction-HF */
int HF(char key[]) {
    return compressionMap( hashcodeMap(key) );
}

/* Khởi tạo bảng băm */
void _init(htNode hastTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hastTable[i].key = i;
        hastTable[i].next = NULL;
    }
}

/* Array to store information */
node arr[10];

/* read data from filename */
void readfile(char *filename, node arr[])
{
    FILE * fp = fopen(filename, "r"); 
    int i;
    
	if ( fp == NULL ) printf("Cannot open file %s\n", filename);
    for (i = 0; i < 10; i++)
    {
        fflush(stdin);
        fscanf(fp, "%s %s %s\n", arr[i].name, arr[i].phone, arr[i].email);
        arr[i].next = NULL;
    }
    fclose(fp);
}

node * makeNew(char name[], char phone[], char email[]) {
    node * tmp = (node*)malloc(sizeof(node));
    if(tmp == NULL) printf("Failed allocate memory!\n");

    strcpy(tmp->name, name); strcpy(tmp->phone, phone); strcpy(tmp->email, email);

    tmp->next = NULL;

    return tmp; 
}

void insert_hT(node x, htNode hastTable[]) {
    /* Tìm thùng chứa */
    int bucket = HF(x.email);

    htNode nodeRef = hastTable[bucket];

    node * new = makeNew(x.name, x.phone, x.email);

    /* Thêm vào cuối */
    if (nodeRef.next == NULL) nodeRef.next = new;
    else
        {
            node * tmp = nodeRef.next;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = new;
        }
}


int main() {
    readfile("Input.txt", arr);
    _init(hastTable);
    for(int i = 0; i < 10; i++) {
	    insert_hT(arr[i], hastTable);
    }
    return 0;
}
