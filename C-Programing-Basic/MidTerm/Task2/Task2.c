#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char stack[100], queue[100]; 
char stack2[100];
int stack_top = -1, queue_top = -1, stack2_top = -1;
bool IsEmpty(int top)
{
    if (top == -1)
        return true;
    else
        return false;
}
void push(char arr[], int *top, char val)
{
    *top = *top + 1;
    arr[*top] = val;
}
char pop(char arr[], int *top)
{
    *top = *top - 1;
    return arr[*top + 1];
}
int main()
{
    char inp[100];
    printf("Input: ");
    fflush(stdin);
    scanf("%s", &inp);
    for (int i = 0; i < strlen(inp); i++)
    {
        if ('0' <= inp[i] && inp[i] <= '9')
        {
            push(queue, &queue_top, inp[i]);
        }
        else if (inp[i] == '*' || inp[i] == '/')
        {
            while (!IsEmpty(stack_top))
            {
                if (stack[stack_top] == '*' || stack[stack_top] == '/')
                {
                    char temp = pop(stack, &stack_top);
                    push(queue, &queue_top, temp);
                }
                else
                    break;
            }
            push(stack, &stack_top, inp[i]);
        }
        else
        {
            while (!IsEmpty(stack_top))
            {
                char temp = pop(stack, &stack_top);
                push(queue, &queue_top, temp);
            }
            push(stack, &stack_top, inp[i]);
        }
    }
    while (!IsEmpty(stack_top))
    {
        char temp = pop(stack, &stack_top);
        push(queue, &queue_top, temp);
    }
    printf("Result 1: ");
    for (int i = 0; i <= queue_top; i++)
    {
        printf("%c ", queue[i]);
    }
    for (int i = 0; i <= queue_top; i++){
        char val = queue[i];
        if ('0' <= val && val <= '9')
        {
            push(stack2, &stack2_top, val);
        }
        else{
            int res;
            int num1 = pop(stack2, &stack2_top) - '0';
            int num2 = pop(stack2, &stack2_top) - '0';
            switch (val)
            {
            case '+':
                res = num1 + num2;
                break;
            case '-':
                res = num2 - num1;
                break;
            case '*':
                res = num1 * num2;
                break;
            case '/':
                res = num2 / num1;
            }
            push(stack2, &stack2_top, res + '0');
        }
    }    
    printf("\nResult 2: %d", pop(stack2, &stack2_top)-'0');
}