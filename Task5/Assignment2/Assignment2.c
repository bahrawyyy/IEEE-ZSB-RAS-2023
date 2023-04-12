#include <stdio.h>



int main()
{
    int hrs,mins,secs,total_time;

    printf("Enter time in format [hh:mm:ss] : ");
    scanf("%d:%d:%d",&hrs,&mins,&secs);

    // Storing the time in a single variable
    total_time = secs + (mins*60) + (hrs *60*60);


    hrs = total_time / (60*60);

    mins = (total_time % 3600) / 60;

    secs = (total_time % 3600) % 60;

    printf("The time you've entered is : ");

    printf("%2d:%2d:%2d\n",hrs,mins,secs);





    return 0;
}