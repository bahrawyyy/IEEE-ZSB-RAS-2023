#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// To be used in size of arrays
#define n 3

int main()
{
    int *intptr = NULL;
    char *str = NULL;
    float *floatptr = NULL;

    int i;


    // Memory allocation
    printf("===== Memory allocation ======\n");

    // Dynamic array of 3 integers 
    intptr = (int *)malloc(n*sizeof(int));
    // printf("%p\n",intptr);
    if(intptr == NULL){
        printf("Memory allocation failed\n");
    }else{
        for(i=0;i<n;i++){
            *intptr = 2*i;
            printf("%d  ",*intptr);
            intptr++;
        }
        printf("\n");
        // printf("%p\n",intptr);
    }
    

    // A string of 18 characters
    str = (char *)malloc(18);
    if(str == NULL){
        printf("Memory allocation failed\n");
    }else{
        strcpy(str,"Better call saul");
        printf("%s\n",str);
    }

    // Dynamic array of 3 floats 
    floatptr = (float *)malloc(n*sizeof(float));
    if(floatptr == NULL){
        printf("Memory allocation failed\n");
    }else{
        for(i=0;i<n;i++){
            *floatptr = 2.5*i;
            printf("%f  ",*floatptr);
            floatptr++;
        }
        printf("\n");
    }

    free(intptr);
    free(str);
    free(floatptr);

    int *int2ndptr = NULL;
    int2ndptr = (int *)malloc(100*sizeof(int));
    // printf("%p\n",intptr);
    if(intptr == NULL){
        printf("Memory allocation failed\n");
    }else{
        for(i=0;i<100;i++){
            *intptr = 2*i;
            printf("%d  ",*intptr);
            intptr++;
        }
        printf("\n");
        // printf("%p\n",intptr);
    }

    free(int2ndptr);
    
    // allocating a large memory space with limited memory
    // may cause memory leakage

    //  If there is not enough memory to allocate 
    // this bigger space, the program may crash.

    return 0;
}