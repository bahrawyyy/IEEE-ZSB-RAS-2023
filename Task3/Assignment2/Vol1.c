#include <stdio.h>
#include <string.h>


typedef struct Date{
    char year[5];
    char month[3];
    char day[3];
}SDate;

int compareTwoDates(SDate date1, SDate date2)
{
    if((!strcmp(date1.day,date2.day)) && (!strcmp(date1.month, date2.month)) && (!strcmp(date1.year, date2.year)))
    {
        return 1;
    }else{
        return 0;
    }   
}



int main()
{

    SDate date1,date2;
    char buffer1[10],buffer2[10];
    printf("Enter first date : (Format : dd mm yyyy)\n");
    scanf("%s %s %s",date1.day,date1.month,date1.year);

    printf("Enter Second date : (Format : dd mm yyyy)\n");
    scanf("%s %s %s",date2.day,date2.month,date2.year);


    if(compareTwoDates(date1,date2)){
        printf("Dates are equal\n");
    }else{
        printf("Not equal\n");
    }


    return 0;
}