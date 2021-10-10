#include <stdio.h>
#include <string.h>

#define MAX_ELEMENT 100

typedef struct phoneList{
    char name[20];
    char phonenumber[20];
    char email[50];
} PhoneList;

int main()
{
    PhoneList list[MAX_ELEMENT];
    int i, num = 1, irc;
    char check[2];

    printf("Start enter information for phone\n ");
    printf("How many people ?");scanf("%d", &num);
    
    for ( i = 0; i < num; i++)
    {
        printf("%d.\n" ,i + 1 );
		printf("name: ");scanf("%s", &list[i].name);
        printf("email address: ");scanf("%s", &list[i].email);
        printf("Phone number: ");scanf("%s", &list[i].phonenumber);

 
        
    }

    //ghi ra file
    FILE *fp;
    if ((fp = fopen("phonebook.dat", "w+b")) == NULL)
    {
        printf("Error can not open file %s", "phonebook.dat");
    }
    irc = fwrite(list, sizeof(PhoneList), num, fp);
    printf("fwrite return code = %d\n", irc); 
    fclose(fp);
    

    //đọc file 
    if ((fp = fopen("phonebook.dat", "rb")) == NULL)
    {
        printf("Error can not open file %s\n", "phonebook.dat");
    }
    irc = fread(list, sizeof(PhoneList), num, fp);
    printf("fread return code = %d\n", irc);

    for ( i = 0; i < num; i++)
    {
        printf("%s\n", list[i].name);
        printf("%s\n", list[i].email);
        printf("%s\n", list[i].phonenumber);
    }
    
    return 0;

}
