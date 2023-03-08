#include <stdio.h>

// Write a program in C to count a total number of duplicate elements in an array.

int countDuplicate(int *arr, int size)
{
    int i,count=0;
    for(i=0;i<size;i++)
    {
        int j;
        for(j=i+1;j<size;j++)
        {
            if(arr[i] == arr[j]){
                count++;
                break;
            }
        }
    }
    return count;
}

int main()
{
    int arr[10] = {1,1,2,3,3,4,5,5,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int count = countDuplicate(arr,size);
    printf("%d",count);

    return 0;
}