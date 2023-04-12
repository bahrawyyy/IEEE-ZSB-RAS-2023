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
    floatptr = (float *)calloc(n,sizeof(float));
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


    printf("===== Memory Reallocation ======\n");

    // Memory Reallocation

    // Reset pointer to start of the array
    floatptr -= n;
    intptr -= n;


    #define new 5
    // Increasing the size of the array to be 5 this time
    intptr = (int *)realloc(intptr,new*sizeof(int));
    // printf("%p\n",intptr);
    if(intptr == NULL){
        printf("Memory reallocation failed\n");
    }else{
        for(i=0;i<new;i++){
            *intptr = 2*i;
            printf("%d  ",*intptr);
            intptr++;
        }
        printf("\n");
    }

    str = (char *)realloc(str,25);
    if(str == NULL){
        printf("Memory reallocation failed\n");
    }else{
        strcpy(str,"Better call saul, suii");
        printf("%s\n",str);
    }

    floatptr = (float *)realloc(floatptr,new*sizeof(float));
    if(floatptr == NULL){
        printf("Memory reallocation failed\n");
    }else{
        for(i=0;i<new;i++){
            *floatptr = 2.5*i;
            printf("%f  ",*floatptr);
            floatptr++;
        }
        printf("\n");
    }


    free(intptr);
    free(str);
    free(floatptr);

    return 0;
}