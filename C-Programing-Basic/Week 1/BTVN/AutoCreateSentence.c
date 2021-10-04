#include <stdio.h>
#include <string.h>
#include<time.h>

int random (int minN, int maxN) {
    return minN + rand() % (maxN + 1 - minN);
}

int main()
{
	int i;
    char article[5][5] = {"the", "a", "one", "some", "any"};
    char noun[5][10] = {"boy", "girl", "dog", "town", "car"};
    char verb[5][10] = {"drove", "jumped", "ran", "waled", "skipped"};
    char preposition[5][10] = {"to", "from", "over", "under", "on"};
    for ( i = 0; i < 5; i++)
    {
        if (article[i][0] >= 'a' && article[i][0] <= 'z')
    {
        article[i][0] = article[i][0] - 32;
    }
    }
    
    for ( i = 0; i < 10; i++)
    {
        printf("%s %s %s %s %s.\n", 
        article[random(0, 4)], 
        noun[random(0, 4)], verb[random(0, 4)], preposition[random(0, 4)], noun[random(0, 4)]);
    }
    return ;

}
