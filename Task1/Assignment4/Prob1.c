#include <stdio.h>

/*
Write a program in C to input a string
and print it.
*/

int main()
{
    char str[100];
    gets(str);
    printf("%s",str);

    return 0;
}