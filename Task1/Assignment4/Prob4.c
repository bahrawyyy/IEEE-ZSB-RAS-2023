#include <stdio.h>


/*
Write a program in C to copy one
string to another string.
*/


int main()
{
    char buffer[100]={0},str[100];
    gets(str);

    int i=0;
    while(str[i]!='\0')
    {
        buffer[i] = str[i];
        i++;
    }
    buffer[i] = '\0';
    printf("%s",buffer);

    return 0;
}