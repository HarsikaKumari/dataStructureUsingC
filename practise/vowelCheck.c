#include <stdio.h>

int vowelCheck(char *word)
{
    char vowel[] = {
        'a',
        'e',
        'i',
        'o',
        'u',
        'A',
        'E',
        'I',
        'O',
        'U',
    };
    int count = 0;
    for (int i = 0; i < sizeof(word) / sizeof(word[0]); i++)
    {
        for (int j = 0; j < sizeof(vowel) / sizeof(vowel[0]); j++)
        {
            printf("%s", word[i]);
        }
    }
}

int main()
{
    char word[] = "harsika";
    vowelCheck(word);
    return 0;
}
