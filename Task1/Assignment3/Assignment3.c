#include <stdio.h>
#include <limits.h>

/*
Write a C code to check the type of the sign representation
technique of your compiler
*/


void PrintBinary(int x)
{
    int i = 7; 
    while(i >= 0){
        printf("%d", (x >> i) & 0x1);
        if(i==4) 
            printf(" ");
        i--;
    }
}


int main()
{
    unsigned int xyz = -1;
    if(xyz == UINT_MAX){
        printf("Compile uses 2's Complement\n");
    }
    printf("%u\n",xyz);     // Two's Complement
    // Representation in binary
    PrintBinary(xyz);

    return 0;
}