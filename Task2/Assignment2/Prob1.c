#include<stdio.h>

int inc(int n)
{

   return (n+1);
}

// Pointer to function
int (* ptr)(int num);



int main()
{
    int a = 4;
    
    ptr = inc;
    printf("%d",ptr(a));
    
    return 0;
}