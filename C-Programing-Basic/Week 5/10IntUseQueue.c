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
    char Place[100];
    char people[100];
    char Description[1000];

    struct TodoList * next;
} TodoList;

TodoList *front = NULL, *rear = NULL;

TodoList * CreateNew ()


