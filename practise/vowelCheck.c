#include <stdio.h>
#include <ctype.h>

int isVowel(char c)
{
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return 1;
    }
    return 0;
}

int countVowel(char str[])
{
    int count = 0;
    int i = 0;
   while(str[i] != '\0')
   {
    if (isVowel(str[i]))
        count++;
    i++;
   }
    return count;
}

int main()
{
    char str[100];
    scanf("%s", &str);
    printf("%d", countVowel(str));
}
