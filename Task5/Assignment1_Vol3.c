#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMaxElement(int arr[],int n)
{
    int i,max=0;
    max = arr[0];
    for(i=0;i<n;i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main()
{
    int n;
    printf("Enter max. length : ");
    scanf("%d",&n);


    char *str = (char *)calloc(n,sizeof(char));
    if(str == NULL) {
      printf("Failed to allocate memory\n");
      return 1;
   }

    // Array of frequency, needs zero initialization
    int *freq = (int *)calloc(n, sizeof(int));
    if(freq == NULL) {
      printf("Failed to allocate memory\n");
      return 1;
   }
    

    printf("Enter your name : ");
    scanf("%s",str);


    int i,temp = 0,j;
    for (i = 0; i < n; i++)
    {
        for(j=0;j<n;j++){
            temp = str[i];
            if(temp == str[j])
                freq[i]++;
        }
        // temp = str[0];
        // if(temp == str[i])
        //     freq[0]++;
    }

    printf("Name : %s\n",str);
    printf("Frequency of the most repeated character : %d",getMaxElement(freq,n));

    free(str);
    free(freq);
}