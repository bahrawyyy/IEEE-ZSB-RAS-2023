// Write a program in C to print all unique elements in an array.

#include <stdio.h>

void printUniqueElements(int *arr, int size)
{   
    int i,count=0;
    for(i=0;i<size;i++)
    {
        int j;
        for(j=0;j<size;j++)
        {
            // Compare elements with each other
            if((i!=j) && (arr[i] == arr[j])){
                count++;
                break;
            }
        }
        if(count == 0)
            printf("%d\t",arr[i]);
        count = 0;
    }
}


int main()
{

    int arr[10] = {1,7,2,3,8,4,5,5,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    printUniqueElements(arr,size);

    return 0;
}
