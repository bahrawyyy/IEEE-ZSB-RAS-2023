#include <stdio.h>


enum Operations {Add='+',Sub='-',Mul='*',Div='/',BitwiseAnd='&',BitwiseOr='|',Not='!'};

int main()
{
    int num1,num2,result=0;
    char operation;
    printf("Enter first opearnd : ");
    scanf("%d",&num1);
    printf("Enter operation (+,-,*,/,&,|,!): ");
    scanf(" %c",&operation);
    printf("Enter second opearnd : ");
    scanf("%d",&num2);
   

    // printf("%d",operation);
    switch(operation)
    {
        case Add:
            result = num1 + num2;
            printf("%d",result);
            break;
        case Sub:
            result = num1 - num2;
            printf("%d",result);
            break;
        case Mul:
            result = num1 * num2;
            printf("%d",result);
            break;
        case Div:
            result = num1 / num2;
            printf("%d",result);
            break;
        case BitwiseAnd:
            result = num1 & num2;
            printf("%d",result);
            break;
        case BitwiseOr:
            result = num1 | num2;
            printf("%d",result);
            break;
        case Not:
            result = !num2;
            printf("%d",result);
            break;
        default:
            printf("Invalid Option\n");
            break;
    }

    // The size of enum will always be the size of integer
    // which is here 4-bytes, As enum is used to store 
    // constant integeres, no matter how many constant
    // it has, the size will always be 4 bytes
    printf("\nSize of enum : %d",sizeof(enum Operations));



    return 0;
}