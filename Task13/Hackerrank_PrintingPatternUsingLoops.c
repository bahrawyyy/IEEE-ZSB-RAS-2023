#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
      
    int SizeOfMatirce = (2*n)-1;
    int arr[SizeOfMatirce][SizeOfMatirce];
    int start = 0;
    int end = SizeOfMatirce-1;
    int j,k;
    while(n!=0)
    {
        for(j=start;j<=end;j++)
        {
            for(k=start;k<=end;k++)
            {
                if(j==end || k==end || j==start || k==start){
                    arr[j][k] = n;
                }
            }
        }
        start++;
        end--;
        n--;
    }
    
    for(j=0;j<SizeOfMatirce;j++)
    {
        for(k=0;k<SizeOfMatirce;k++)
        {
            printf("%d ",arr[j][k]);
        }
        printf("\n");
    }

    return 0;
}
