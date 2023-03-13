#include <stdio.h>





int main()
{
    int *ptr;
    *ptr = 0xA0A1A2;

    printf("%x\n",*ptr);


    printf("The ++ has a higher precedence than dereference *, even if it is post increment\n");
    printf("It should print garbage value, it may lead to segmentation fault\n");
    *ptr++;
    printf("%x\n",*ptr);

    printf("The ++ has a higher precedence than dereference *\n");
    printf("It should print garbage value, it may lead to segmentation fault\n");
    *ptr++;
    printf("%x\n",*ptr);

    printf("Now the pointer has a corrupted data\n");
    printf("So if we do the following operations, it will increment the last garbage value\n");
    ++*ptr;
    printf("%x",*ptr);

    // If we comment the first two operations, and perfrom 
    // the third operation, it should print 0xA0A1A3
    // as the derefernce will happen first 
    // There is no conflict for the compiler here


}