#include <stdio.h>


#define MySizeOf(variable) (char *)(&variable + 1)-(char *)(&variable)


// Macros are faster than inline functions as they
// are just text replacement 
// There is no context switching

#define type_t double

static inline int CalcSizeOf(type_t var) {
    return (char *)(&var + 1)-(char *)(&var);
}

// Inline functions are preferable when debugging and optimization



int main()
{
    int arr[5];
    int x;
    double c;
    printf("Size of array is %d",MySizeOf(arr));
    printf("\nSize of vriable is %d",CalcSizeOf(c));

    return 0;
}
