#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int day, month, year;
} time;
typedef struct TodoList
{
    time moment;
    char Place[50];
    char people[20];
    char Description[50];

    struct TodoList * next;
} TodoList;

TodoList *front = NULL, *rear = NULL;

TodoList * CreateNew (char* Description, char* place, char* people, time  moment)
{
    TodoList * tmp = (TodoList*)malloc(sizeof(TodoList));
    strcpy(tmp->Description, Description);
    strcpy(tmp->Place, place);
    strcpy(tmp->people, people);
    tmp->moment.day = moment.day; tmp->moment.month = moment.month; tmp->moment.year = moment.year;
    tmp->next = NULL;

    return tmp;
}

int EmptyQueue()
{
    return front == NULL && rear == NULL;
}

void PushTodoList (char* Description, char* place, char* people, time  moment)
{
    TodoList* tmp = CreateNew(Description, place, people, moment);
    if (EmptyQueue()) {front = tmp; rear = tmp;}
    else
    {
        rear->next = tmp;
        rear = tmp;
    }
    
}

void PrintQueue()
{
    TodoList * cur = front;
    if (EmptyQueue())
    {
        printf("Todo List is empty. ! Please push to Todo List\n");
    }
    else
    {
        printf("%3s%20s%30s%30s%30s\n", "STT", "Mo ta", "Dia diem", "Voi", "Thoi gian");
        for ( cur ; cur != NULL; cur = cur->next)
        {
            int i = 1;
            printf("%d %20s%30s%30s                          %d/%d/%d\n", 
            i, cur->Description, cur->Place, cur->people, cur->moment.day, cur->moment.month, cur->moment.year);
            ++i;
    	}
    }
      
}
TodoList* SearchByDescription(char * Description)
{
    TodoList * cur = front;
    for ( cur ; cur != NULL ; cur = cur->next)
    {
        if (strcpy(cur->Description, Description) == 0)
        {
            return cur;
        }
        
    }
    return NULL;
}
void Pop(TodoList * position)
{
    TodoList * cur = front;
    for ( cur ; cur != NULL; cur = cur->next)
    {
        if (cur == position)
        {
            cur->next = cur->next->next;
            free(position);
        }
        
    }
}

void ModifyingDealine(char * Description, time  newDeadline)
{
    TodoList* tmp = SearchByDescription(Description);
    tmp->moment.day = newDeadline.day;
    tmp->moment.month = newDeadline.month;
    tmp->moment.year =newDeadline.year;
}

int main()
{
	int choice;
    printf("MENU\n1.In danh sach cac viec can lam.\n2.Them vao danh sach.\n3.Xoa mot viec sau khi da lam xong.\n4.Gia han thoi gian.\n5.Thoat\n");
    for(;;)
    {
        printf("Ban chon so : "); scanf("%d", &choice);
        if (choice == 1)
        {
            PrintQueue();
        }
        if (choice == 2)
        {
            char Description[50], place[50], peopl[20] ;
            time  date ;
            printf("Ten viec can lam: "); scanf("%s", Description);
            printf("Dia diem: "); scanf("%s", place);
           	printf("Ban lam viec nay voi : "); scanf("%s", peopl);
            printf("Thoi gian dd/mm/yy: "); fscanf(stdin,"%d/%d/%d", &date.day, &date.month, &date.year);
            PushTodoList(Description, place, peopl, date);
        }
        if (choice == 3)
        {
            char Description[100];
            printf("Ten viec da lam xong: "); scanf("%s", Description);
            Pop(SearchByDescription(Description));
        }
        if (choice == 4)
        {
            char Description[100];
            time  newDealine;
            printf("Viec ban can them thoi gian: ");
            scanf("%s", Description);
            printf("Thoi han moi dd/mm/yy: ");
            fscanf(stdin, "%d/%d/%d", &newDealine.day, &newDealine.month, &newDealine.year);
            ModifyingDealine(Description, newDealine);
        }
        if (choice == 5)
        {
            printf("Hen gap lai !\n");
            exit(-1);
        }
    }
    
    return 0;
    
}
