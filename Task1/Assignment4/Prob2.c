#include <stdio.h>

/*
Write a program in C to separate the
individual characters from a string.
*/

int main()
{
    char str[100];
    gets(str);
    int i = 0;
    while(str[i] != '\0')
    {
        printf("%c ",str[i]);
        i++;
    }




    return 0;
}