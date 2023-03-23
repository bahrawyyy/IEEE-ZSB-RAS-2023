#include <stdio.h>

int arr[10];
int n;

void swap(int *a, int *b);
void takeInput(void);
int* sortAscending();
int* sortDecending();
void printArray(int array[],int size);

#define SORT_ASCENDING 0
#define SORT_DECENDING 1
#define SORT_TYPE SORT_DECENDING

int main()
{
    #ifdef SORT_TYPE
    takeInput();
    int *arrayxx;
    #if SORT_TYPE == SORT_ASCENDING
        arrayxx = sortAscending();
        printf("In Ascending order \n");
        printArray(arrayxx,n);
    #elif SORT_TYPE == SORT_DECENDING
        arrayxx = sortDecending();
        arrayxx = sortDecending();
        printArray(arrayxx,n);
    #endif
    #endif
    #ifndef SORT_TYPE
        #error "You have to determine in which order"
    #endif
    
    return 0;
}


void printArray(int array[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",array[i]);
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void takeInput(void)
{
    printf("Enter no. of inputs : ");
    scanf("%d",&n);
    int i;
    printf("Enter values : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

int* sortAscending()
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[j] < arr[i])
                swap(&arr[j],&arr[i]);
        }
    }
    return arr;  
}

int* sortDecending()
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[j] > arr[i])
                swap(&arr[j],&arr[i]);
        }
    }
    return arr;  
}