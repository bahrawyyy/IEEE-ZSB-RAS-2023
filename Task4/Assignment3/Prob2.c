#include <stdio.h>

#define ADDITION 0
#define SUBTRACTION 1
#define OPERATION_MODE SUBTRACTION


#define ADD(NUM1,NUM2) (NUM1)+(NUM2)
#define SUB(NUM3,NUM4) (NUM3)-(NUM4)

int main()
{
    #ifdef OPERATION_MODE
    int num1,num2;
    printf("Enter two numbers : ");
    scanf("%d %d",&num1,&num2);

    #if OPERATION_MODE ==  ADDITION
        printf("%d",ADD(num1,num2));

    #elif OPERATION_MODE ==  SUBTRACTION
        printf("%d",SUB(num1,num2));

    #endif

    #endif
    #ifndef OPERATION_MODE
        #error "You must decide which operation to execute"
    #endif












    return 0;
}