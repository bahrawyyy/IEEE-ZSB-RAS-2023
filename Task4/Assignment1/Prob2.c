#include <stdio.h>


typedef struct complex{
    int real;
    int imag;
}SComplex;

SComplex AddComplex(SComplex num1, SComplex num2)
{
    SComplex Sum;
    Sum.real = num1.real + num2.real;
    Sum.imag = num1.imag + num2.imag;
    return Sum;
}

int main()
{
    SComplex num1 = {12, 3};
    SComplex num2 = {14, 5};
    SComplex Result = AddComplex(num1,num2);
    printf("%d + %dj",Result.real,Result.imag);

    return 0;
}