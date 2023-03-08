#include <stdio.h>
#include <string.h>

/*
Write a program in C to compare two
strings without using string library
functions.
*/


int max(int a,int b)
{
    return (a>=b)?a:b;
}

int stringCompare(char *str1, char *str2)
{
    int MaxLength = max(strlen(str1),strlen(str2));
    int i;
    for(i=0;i<MaxLength;i++)
    {
        if(str1[i] > str2[i]){
            return 1;
        }else if(str1[i] < str2[i]){
            return -1;
        }
    }
    return 0;
}


int main()
{
    char str1[100],str2[100];
    printf("Enter first string : ");
    gets(str1);
    printf("Enter second string : ");
    gets(str2);
    printf("%d",stringCompare(str1,str2));




    return 0;
}