#include<stdio.h>



int main()
{
    int a[5] = {4,7,9,11,2};
    int *ptr = NULL;
    ptr = a;
    int i;
    for(i=0;i<5;i++)
    {
        printf("%d\n",*ptr++);
    
    }
  
    return 0;
}