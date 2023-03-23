#include <stdio.h>
#include <stdbool.h>




typedef unsigned char uint8_t;
typedef signed char sint8_t;

typedef unsigned short uint16_t;
typedef signed short sint16_t;

typedef unsigned int uint32_t;
typedef signed int sint32_t;

typedef unsigned long long uint64_t;
typedef signed long long sint64_t;

typedef bool Boolean;
typedef float f32;
typedef double f64;

int main()
{   
    printf("Size of uint8_t : %d\n",sizeof(uint8_t));
    printf("Size of sint8_t : %d\n",sizeof(sint8_t));
    printf("Size of uint16_t : %d\n",sizeof(uint16_t));
    printf("Size of sint16_t : %d\n",sizeof(sint16_t));
    printf("Size of uint32_t : %d\n",sizeof(uint32_t));
    printf("Size of sint32_t : %d\n",sizeof(sint32_t));
    printf("Size of uint64_t : %d\n",sizeof(uint64_t));
    printf("Size of sint64_t : %d\n",sizeof(sint64_t));
    printf("Size of f32 : %d\n",sizeof(f32));
    printf("Size of f64 : %d\n",sizeof(f64));
    printf("Size of Boolean : %d\n",sizeof(Boolean));

    return 0;
}