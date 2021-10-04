#include<string.h>
#include<stdio.h>
#define STR_LEN 100
void replace (char *str, char *c, char *c2)
{
	char *p = str;
    while (*p != NULL){
       if (*p == *c)
       {
           *p = *c2;
       }
       ++p;
   } 

}
int main()
{
    char replace_what[2], replace_with[2];
    char str[STR_LEN + 1];
    printf("enter a not space string: ");
    scanf("%100s", str);
    printf("Letter to replace: ");
    scanf("%s", &replace_what);
    printf("Letter to replace with: ");
    scanf("%s", &replace_with);
    replace(str, replace_what, replace_with);
	printf("The result: %s", str);
    return 0;

}


