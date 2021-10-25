#include <stdio.h>
#include <string.h>

typedef struct PhoneAdd
{
    char PhoneNum[15];
    struct PhoneAdd * next;
} PhoneAdd;

PhoneAdd * CreateNew(char * Num)
{
    PhoneAdd * tmp;
    tmp = (PhoneAdd*)malloc(sizeof(PhoneAdd));
    strcpy(tmp->PhoneNum, Num);
    tmp->next = NULL;
    return tmp;
}

PhoneAdd* FindLast( PhoneAdd * head)
{
    if (head = NULL)
    {
        return head;
    }
    PhoneAdd *cur = head;
    while (cur != NULL)
    {
        cur = cur->next; 
    }
    return cur;
    
}

PhoneAdd* InsertPhone( PhoneAdd *head, int p, char *Num)
{
    int count = 0;
    PhoneAdd* tmp;
    while (tmp !=  NULL)
    {
        tmp = tmp->next;
        count++;
    }

    // chèn vào đầu
    if ( p == 0 )
    {
        PhoneAdd *tmp;
        tmp->next = head;
        strcpy(tmp->PhoneNum, Num);
        head = tmp;
        return head;
    }
    
    //chèn vào cuối nếu p lớn hơn số phần tử
    if ( p >= count )
    {
        PhoneAdd *tmp;
        tmp = FindLast( head );
        PhoneAdd * cur = CreateNew(Num);
        tmp->next = cur;
        return head;
    }

    // chèn vào giữa
    if (0 < p && p < count )
    {
        PhoneAdd* tmp =  head;
        for ( i = 1; i <= p  ; i++)
        {
            tmp = tmp->next;
        }
        PhoneAdd *cur = CreateNew( Num );
        cur->next = tmp;
        tmp->next = cur;
        tmp = tmp->next;
        return head;
    }
    
}

void PrintList( PhoneAdd *head)
{
    PhoneAdd *tmp = head;
    while(tmp != NULL)
    {
        printf("%s\n", tmp->PhoneNum);
        tmp = tmp->next;
    }
}

PhoneAdd *Delete (PhoneAdd *head, int p)
{
    if (p == 0)
    {
        PhoneAdd *tmp = head;
        head = tmp->next;
        free(tmp);
        return head;
    }
    
    int count = 0;
    PhoneAdd* tmp;
    while (tmp !=  NULL)
    {
        tmp = tmp->next;
        count++;
    }

    if (p >= count )
    {
        PhoneAdd *tmp = FindLast( head );
        tmp->next = NULL;
        return head;
    }

    if (p > 0 && p < count)
    {
        PhoneAdd *cur = head, *prev = head;
        int i;
        for ( i = 0; i <= p ; i++)
        {
            cur = cur->next;
        }
        for ( i = 0; i < p; i++)
        {
            prev = prev->next;
        }
        prev->next = cur->next;
        free(cur);
        return head; 
    }
       
}

PhoneAdd *Input()
{
    PhoneAdd head = NULL;
    
}