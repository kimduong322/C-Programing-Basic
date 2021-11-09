#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Name_Len 50
#define ID_LEN 8
#define notFound -1

typedef struct std
{
    char id[ID_LEN + 1 ];
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

// Hàm Counter sẽ đếm số lượng phần tử trong danh sách liên kết
int Counter()
{
    int count = 0;
    student* cur = root;
    while (cur != NULL )
    {
        cur = cur->next;
        ++count;
    }
    return count;
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

//Hàm SortByName sẽ sắp xếp danh sách liên kết theo thứ tự của tên theo bảng chữ cái Alphabet
void SortByName()
{
    student* tmp1, *tmp2 ;
    char id[8+1], name[50+1]; double grade;
    for ( tmp1 = root; tmp1 != NULL; tmp1 = tmp1->next)
    {
        for ( tmp2 = tmp1->next; tmp2 != NULL; tmp2 = tmp2->next)
        {
            if (strcmp(tmp1->name, tmp2->name) > 0)
            {
                strcpy(id,tmp1->id); strcpy(tmp1->id, tmp2->id); strcpy(tmp2->id, id);
                
                strcpy(name,tmp1->name); strcpy(tmp1->name, tmp2->name); strcpy(tmp2->name, name);
                
                grade = tmp1->grade; tmp1->grade = tmp2->grade; tmp2->grade = grade; 
                
            }
        }
        
    }
}

/*Hàm Name sẽ nhận vào vị trí của mảng và trả về tên của học sinh ở 
 vị trí đó trong danh sách liên kết*/

char* Name(int position)
{
    student * cur = root;
    int count ;
    for ( count = 0; count < position; count++)
    {
        cur = cur->next;
    }
    return cur->name;
}
//Hàm binSearchName sẽ tìm kiếm nhị phân theo tên
int binSearchName(char *name){
    int Low = 0,
        Hight = Counter()-1,
        mid;
    while(Low <= Hight){
        mid = (Low + Hight)/2;
        if ( strcmp( Name(mid), name) < 0 ) Low = mid + 1;
        else if ( strcmp( Name(mid), name) > 0 ) Hight = mid - 1;
        else return mid;
    }
    return notFound;
}
//Hàm Grade sẽ trả về điểm của học sinh ở vị trí positon
double Grade(int position)
{
    student * cur = root;
    int count;
    for ( count = 0; count < position; count++)
    {
        cur = cur->next;
    }
    return cur->grade;
}

//Hàm binSearchGrade sẽ tìm kiếm nhị phân theo điểm
int binSearchGrade(double grade)
{
    int Low = 0,
        Hight = Counter()-1,
        mid;
    while(Low <= Hight){
        mid = (Low + Hight)/2;
        if ( Grade(mid) < grade ) Low = mid + 1;
        else if ( Grade(mid) > grade ) Hight = mid - 1;
        else return mid;
    }
    return notFound;
}

//Hàm Profile sẽ in về thông tin của sinh viên
void Profile(int position)
{
    student * cur = root;
    int count ;
    if(position == -1)
    {
        printf("Khong co sinh vien nao nhu vay trong danh sach !\n");
    }
    else
    {
        for ( count = 0; count < position; count++)
        {
            cur = cur->next;
        }
        printf("%s %s \n", cur->name, cur->id);
    }
    
}

int main(){
    int pos1, pos2;
    //Khởi tạo danh sách liên kết
    InitialList();
    LoadFile("StdManageData.txt");
    PrintList();
   
    //Tìm kiếm nhị phân theo tên
    char NAME[]="TranHuuDo";
    SortByName();
    pos1 = binSearchName(NAME);
    PrintList();
    Profile(pos1);

    //Tìm kiếm nhị phân theo điểm
    double GRADE = 4.0;
    SortByGrade();
    pos2 = binSearchGrade(GRADE);
    PrintList();
    Profile(pos2);

    return 0;
}
