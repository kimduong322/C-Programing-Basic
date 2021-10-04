#include <stdio.h>
#include <string.h>
#define ALPHABET_LEN 26

int main ()
{
    char str[100];
    int count[ALPHABET_LEN]={0}, i;

    printf("enter string: ");
    gets(str);
    strlwr(str);

    for ( i = 0; i < strlen(str); i++)
    {
        char c = str[i];
        if (c >= 'a' && c <= 'z')
        {
            ++count[c - 'a'];
        }
        
    }
    for ( i = 0; i < ALPHABET_LEN; i++)
    {
        if (count[i] > 0)
        {
            printf("The letter '%c' is appear %d time(s)\n", i + 'a', count[i]);
        }
        
    }
    
    return 0;
}
