#include <stdio.h>
#include <String.h>
#include <time.h>
#include <stdlib.h>

void BruteForceMath (char T[], char P[])
{
    int n = strlen(T), m = strlen(P);
    // dịch cửa sổ từng kí tự
    for (int i = 0; i < n - m; i++)
    {
        int j;

        // Ở vị trí i hiện tại, kiểm tra xem cửa sổ có khớp với P hay không
        for (j = 0; j < m; j++)
        {
            if(T[i + j] != P[j])
                break;
        }
            // P[0,1,...,m-1] = T[i,i+1,...,i+m-1]
        if (j == m)
            printf("Pattern found in index %d \n", i);
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

    char stringSource[6] = "abcdef" ;
    int stringlen = 2000;
    char Text[stringlen + 1];// = (char*)malloc(stringlen * sizeof(char));
    RandomStringGenerator (stringSource, Text, stringlen);
    
    char Pattern[6] = "aa";
    
   
    BruteForceMath(Text, Pattern);
    return 0;
}