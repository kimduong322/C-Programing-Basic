#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Name_Len 50
#define ID_LEN 8

typedef struct std
{
    char PhoneNumb[12];
    char Name[50];
    char Email[50];
    struct std * next;    
} Address ;

Address *root, *last;

// InitailList là hàm gán NULL cho 3 con trỏ root và last
void InitialList()
{
    root = NULL;
    last = NULL;
}

// ListEmpty là hàm kiểm tra xem danh sách có trống không ?
int ListEmpty()
{
    return root ==  NULL && last == NULL;
}

Address * MakeAdd (char *PhoneNumb, char* Name, char * Email)
{
    Address *profile = (Address*)malloc( sizeof(Address) );
    strcpy(profile->PhoneNumb, PhoneNumb);
    strcpy(profile->Name, Name);
    strcpy(profile->Email, Email);
    profile->next = NULL;

    return profile;
}

// hàm InsertLast có đầu vào là  PhoneNumb, Name, grade
void InsertLast(char* PhoneNumb, char* Name, char * Email)
{
    Address *std = MakeAdd (PhoneNumb, Name, Email);
    if (ListEmpty())    
    {
        root = std; last = std;
    }
    else
    {
        last->next = std;
        last =  std;
    }
    
}

// Hàm LoadFile đọc dữ liệu từ file và lưu vào cuối danh sách liên kết
void LoadFile(char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp  == NULL)
    {
        printf("Can not open file %s\n", filename);
    }
    char PhoneNumb[12+1], Name[50+1], Email[50+1];   
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s\n", Name, PhoneNumb, Email);
        InsertLast(PhoneNumb, Name, Email);
    }
    fclose(fp);
}

//Hàm SortByName sẽ sắp xếp danh sách liên kết theo ten
void SortByName()
{
    Address* tmp1, *tmp2 ;
    
    char PhoneNumb[12], Name[50]; char Email[50];
    
    for ( tmp1 = root; tmp1 != NULL; tmp1 = tmp1->next)
    {
        for ( tmp2 = tmp1->next; tmp2 != NULL; tmp2 = tmp2->next)
        {
            if (strcmp(tmp1->Name, tmp2->Name) < 0)
            {
                strcpy(PhoneNumb,tmp1->PhoneNumb); strcpy(tmp1->PhoneNumb, tmp2->PhoneNumb); strcpy(tmp2->PhoneNumb, PhoneNumb);
                
                strcpy(Name,tmp1->Name); strcpy(tmp1->Name, tmp2->Name); strcpy(tmp2->Name, Name);
                
                strcpy(Email,tmp1->Email); strcpy(tmp1->Email, tmp2->Email); strcpy(tmp2->Email, Email);
                
            }
        }
       
    }
}

// Hàm FindAddById sẽ tìm Address có Name giống như vậy và trả về con trỏ
void FindAddByName(char *Name)
{
    Address* cur;
    for ( cur = root; cur != NULL   ; cur = cur->next)
    {
        if (strcmp(cur->Name, Name) == 0 )
        {
            printf("%s %s %s\n", cur->Name, cur->PhoneNumb, cur->Email); 
        }   
    }   
}

int main()
{
    LoadFile("Input.txt");
    SortByName();
    FindAddByName("NguyenVanThienAnh");
    return 0;
}