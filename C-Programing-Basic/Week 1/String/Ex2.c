#include <string.h>
#include <stdio.h>

int main()
{
    char Str[50] = "Dao Kim            Duong 20205075";
    printf("%s \n", Str);
    char Symbol[2] = " ";
    char *token = strtok(Str, Symbol);
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, Symbol);
    }
    return 0;
}
