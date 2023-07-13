#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {


    char num[1000];
    fgets(num,1000,stdin);
    
    int i=0,j=0;
    int frequencyArray[10] = {0};
    
    while(num[j]!='\0')
    {
        for(i=0;i<10;i++){
            if(num[j] == (i+'0')){
                frequencyArray[i]++;
                break;  // Break once this char matches a number from 0 to 9
            }
        }
        j++;
    }
    

    
    
    for(i=0;i<10;i++)
    {
        printf("%d ",frequencyArray[i]);
    } 
     
    return 0;
}
