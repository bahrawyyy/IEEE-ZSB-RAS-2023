#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printUniqueChars(char *str)    
{
    int i = 0,j,count = 0,temp;
    for(j=0;str[j]!='\0';j++){
        count = 0;
        temp = str[j];
        for(i=0;str[i]!='\0';i++){
            if(temp == str[i])
                count++;
        }
        // printf("%c %d\n",str[j],count);
        if(count == 1)
            printf("%c",str[j]);
    }
    printf("\n");
}

int main()
{


   printf("Enter strings and !! to stop : \n");
   char str[20];
   while(1)
   {
    gets(str);

    if(!strcmp(str,"!!"))
        break;


    printUniqueChars(str);
   }

    return 0;
}