#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void computeLPSarray(char pattern[], int M, int lps[]) // M = strlen(pattern)
{
    // lps[0] always is 0 (lps[0] = 0)
    lps[0] = 0;

    // len of the previous longest prefix-subfix
    int len = 0; // len = lps[0]

    // compute lps for i = 1 to M-1
    int i = 1;
    while (i < M)       
    {
        // The previous longest prefix-subfix is pattern[0], pattern[1], ..., pattern[len - 1]
        if(pattern[i] = pattern[len]) 
        {
            lps[i] = len + 1;
            len = lps[i];
            i++;            
        }
        else // pattern[i] != pattern[len]
             // len = lps[len - 1] and return (if(pattern[i] = pattern[len])....) 
            {
                if (len != 0) len = lps[len - 1]; // not increment i here for returning
                else    
                    //if(len == 0)
                    {
                        lps[i] = 0; 
                        i ++;
                    }
            }   

    }   
}

void KMPsearch(char Text[], char Pattern[]) {
    int n = strlen(Text);
    int m = strlen(Pattern);

    // Khai báo mảng chứa lps của pattern
    int lps[m];

    // Tính lps
    computeLPSarray(Pattern, m, lps);

    int i = 0; //index for Text
    int j = 0; // index for Pattern

    while (i < n)   
    {
        if (Pattern[j] == Text[i])
        {
            ++j;
            ++i;
        }

        if (j == m)
        {
            printf("found pattern at index %d\n", i - j);
            j = lps[j-1];
        }
        else if (i < n && Pattern[j] != Text[i])
        {
            if(j != 0) {
                j = lps[j-1];
            }
            else
                i = i+1;
        }
    }
    
}

// Sinh một chuỗi kí tự ngẫu nhiên độ dài resultLen có trong tập stringSource vào con trỏ result
void RandomStringGenerator (char stringSource[], char  result[] ,int resultLen) {
    int stringSourcelen = strlen(stringSource);
    
    // Mỗi phần tử được sinh một cách ngẫu nhiên trong tập các kí tự stringSource cho trước
    for (int i = 0; i < resultLen; i++)
    {
        result[i] = stringSource[rand() % stringSourcelen];
    }
    result[resultLen] = '\0';
}

int main() {
    srand(time(0));

    char strSource[6] = "abcde";
    int stringlen = 2000;
    char Text[stringlen + 1];

    RandomStringGenerator(strSource, Text, stringlen);

    char Pattern[3] = "aa";
    KMPsearch(Text, Pattern);
    
    return 0;
}