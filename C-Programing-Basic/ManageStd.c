#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Name_Len 50
#define ID_LEN 8

typedef struct std
{
    char id[ID_LEN + 1];
    char name[Name_Len +1 ];
    double grade;
    struct std *next;    
} student ;

student *root, *last;

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

student * MakeProfileStd (char *id, char* name, double grade )
{
    student *profile = (student*)malloc( sizeof(student) );
    strcpy(profile->id, id);
    strcpy(profile->name, name);
    profile->grade = grade;
    profile->next = NULL;

    return profile;
}

// hàm InsertLast có đầu vào là  id, name, grade
void InsertLast(char* id, char* name, double grade)
{
    student *std = MakeProfileStd (id, name, grade);
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
    char id[8+1], name[50+1];
    double grade;
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %lf\n", id, name, &grade);
        InsertLast(id, name, grade);
    }
    fclose(fp);
}

//Hàm PrintList sẽ in ra danh sách sinh viên gồm id, name và grade
void PrintList (){
    student* cur = root;
    printf("%8s%50s%15s\n", "ID", "NAME", "GRADE");
    while (cur != NULL)
    {
        printf("%8s%50s%15lf\n", cur->id, cur->name, cur->grade);
        cur = cur->next;
    }  
}

//Hàm SortByGrade sẽ sắp xếp danh sách liên kết theo chiều tăng của điểm và trả về con trỏ root
void SortByGrade()
{
    student* tmp1, *tmp2 ;
    
    char id[8+1], name[50+1]; double grade;
    
    for ( tmp1 = root; tmp1 != NULL; tmp1 = tmp1->next)
    {
        for ( tmp2 = tmp1->next; tmp2 != NULL; tmp2 = tmp2->next)
        {
            if (tmp1->grade < tmp2->grade)
            {
                strcpy(id,tmp1->id); strcpy(tmp1->id, tmp2->id); strcpy(tmp2->id, id);
                
                strcpy(name,tmp1->name); strcpy(tmp1->name, tmp2->name); strcpy(tmp2->name, name);
                
                grade = tmp1->grade; tmp1->grade = tmp2->grade; tmp2->grade = grade; 
                
            }
        }
        
    }
}

// Hàm FindStdById sẽ tìm std có id giống như vậy và trả về con trỏ
student* FindStdById(char *ID)
{
    student* cur;
    for ( cur = root; cur != NULL   ; cur = cur->next)
    {
        if (strcmp(cur->id, ID) == 0 )
        {
            return cur; break;
        }   
    }
    return NULL;
}

//Hàm DelById sẽ xóa một hồ sơ sinh viên trong danh sách liên kết theo ID
void DelById(char* ID)
{
    student* tmp = FindStdById(ID);
    student* cur = root ;
    while (cur != tmp)
    {
        cur = cur->next;
    }
    
    cur->next = tmp->next;
    free(tmp); 
}

void ExportFile(char* filename)
{
    FILE* fp =  fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Can not open file %s", filename);
    }
    
    student* cur ;
    for ( cur = root; cur != NULL; cur = cur->next  )
    {
        fprintf(fp, "%s %s %.2lf\n", cur->id, cur->name, cur->grade);
    }
    fclose(fp);
}

int main()
{
    InitialList();
    
    int choice;
    printf("MENU\n1.Doc danh sach tu file\n2.In danh sach\n3.Xoa mot ho so\n");
    printf("4.Tim kiem ho so\n5.Sap xep ho so theo diem\n6.Luu ho so vao file\n7.Thoat\n");
    printf("Ban lua chon so: "); scanf("%d", &choice);
    while (choice >= 1 && choice <= 7 )
    {
            if (choice == 1)
        {
            char filename[100];
            printf("Nhap ten file: "); scanf("%s", filename);
            LoadFile(filename);
        }
        else if (choice == 2)
        {
            PrintList();
        }
        else if (choice == 3)
        {
            char id[ID_LEN + 1];
            printf("Nhap ID can xoa: "); scanf("%s", id);
            DelById(id); PrintList();
        }
        
        else if (choice == 4)
        {
            char id[ID_LEN + 1];
            printf("Nhap ID can tim kiem: "); scanf("%s", id);
            student* tmp = FindStdById(id);
            printf("%s %s\n", tmp->id, tmp->name);
        }
        
        else if (choice == 5)
        {
            SortByGrade();
            PrintList();
        }
        else if (choice == 6)
        {
            char filename[100];
            printf("Enter name of file: "); scanf("%s", filename);
            ExportFile(filename);
        }
        else if (choice == 7)
        {
            printf("\nHen gap lai !");
            exit(-1);
        }
        printf("Ban chon so nao tiep theo: ");
        scanf("%d", &choice);
    }
    
    
    return 0;
}
