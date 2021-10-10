#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *str1, char *str2)
{
    int len1 = strlen(str1), len2 = strlen(str2);
    char *result = (char *)malloc((len1 + len2 + 1 * sizeof(char)));
    if (result == NULL)
    {
        printf("Allacation failed! Check memory\n");
        return NULL;
    }
    
    strcpy(result, str1);
    strcpy(result + len1, str2);
    return result;
}

int main()
{
    char str1[] = "hello world", str2[] = "how are you ?";
    char *ptr = my_strcat(str1, str2);
    if (ptr == NULL)
    {
        printf("Problem allocating memory!\n");
        return 1;
    }
    
    printf("%s",ptr); 
    free(ptr);
    return 0;
}
