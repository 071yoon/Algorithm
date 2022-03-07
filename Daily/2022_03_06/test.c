#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	sumAB(int a, int b);
int	mulAB(int a, int b);
int	strlen(unsigned char *str);
int	howmanycharacters(unsigned char *str);
int	howmanydots(unsigned char *str);
int	howmanywords(unsigned char *str);

int main()
{
    int bigMENU = 0;
    int smallMENU;
    int a, b, result;



    printf("please input your menu :\n 1 : TempConvert\n 2 : String Length\n 3 : Calculator\n 4 : String Component Analyzer\n");
    scanf("%d", &bigMENU);
    printf("\n");

    if (bigMENU == 1) // 섭씨 화씨 변환
    {
        float fahr = 0;
        float celcius = 0;
        int lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        while (fahr <= upper)
        {
            celcius = (5.0 / 9.0) * (fahr - 32.0);
            printf("fahr = %3.0f celcius = %6.1f\n", fahr, celcius);
            fahr = fahr + step;
        }

    }
    else if (bigMENU == 2) // string length
    {
        int len;
        unsigned char *str = "Some where over the rainbow";

        printf("strlen : return length of string\n");
        printf("string = \"%s\"\n", str);
        len = strlen(str);
        printf("strlen : %d\n", len);

    }
    else if (bigMENU == 3) // Calculator
    {
        while (1)
        {
            printf("1 : ADD, 2 : MUL, 3 : quit\n");
            scanf("%d", &smallMENU);
            if (smallMENU == 3)
                break;
            printf("a : ");
            scanf("%d", &a);
            printf("b : ");
            scanf("%d", &b);
            switch (smallMENU) {
            case 1:
                result = sumAB(a, b);
                printf("%d + %d = %d\n\n", a, b, result);
                break;
            case 2:
                result = mulAB(a, b);
                printf("%d * %d = %d\n\n", a, b, result);
                break;
            default: break;
            }

        }

    }
    else if (bigMENU == 4) // string component analyzer
    {
        int count_sentences = 0;
        int count_characters_wb = 0;
        int count_characters_wob = 0;
        int count_words = 0;
        unsigned char sen[300];

        printf("Type your sentence.");
        
        scanf(" %[^\n]s", &sen);

        count_sentences = howmanydots(sen);
        count_words = howmanywords(sen) + 1;
        count_characters_wb = strlen(sen);
        count_characters_wob = howmanycharacters(sen);


        printf("string = \"%s\"\n", sen);
        printf("character count without spacebar considered : %d\n", count_characters_wob);
        printf("character count with spacebar consideration : %d\n", count_characters_wb);
        printf("Sentence count : %d\n", count_sentences);
        printf("word count : %d\n", count_words);

    }
    return 0;
}

int strlen(unsigned char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }
    return i;
}

int howmanydots(unsigned char *str)
{
    int j = 0;
    int dots = 0;
    while (str[j] != '\0')
    {
        j++;
        while (str[j] == '.')
        {
            ++dots;
            break;
        }
    }
    return dots;
}

int howmanywords(unsigned char *str)
{
    int j = 0;
    int words = 0;
    while (str[j] != '\0')
    {
        j++;
        while (str[j] == ' ')
        {
            ++words;
            break;
        }
    }
    return words;
}

int howmanycharacters(unsigned char *str)
{
    int j = 0;
    int chars = 0;
    while (str[j] != '\0')
    {
        j++;
        while (str[j] != ' ')
        {
            ++chars;
            break;
        }
    }
    return chars;
}

int sumAB(int a, int b)
{
    return a + b;
}

int mulAB(int a, int b)
{
    return a * b;
}

https://prod.liveshare.vsengsaas.visualstudio.com/join?35F5EA818B6BD88117E75E191BA1D2CD1BAB