#include <stdio.h>


typedef struct student_info{
    int roll_number;
    char* name;
    int age;
    char* address;
    int marks;
}student;


// A function to count number of
// students with marks less than 12 if the full
// mark is of 20.

int countFailed(student s[])
{
    int i,count=0;
    for(i=0;i<15;i++)
    {
        if(s[i].marks < 12)
            count++;
    }
    return count;
}

int main()
{
    student S[15] = {
        {1,"Abdalla",22,"Sharkia",18},
        {2,"Ahmed",21,"Cairo",11},
        {3,"Leo",12,"Giza",19},
        {4,"Me3za",33,"Bunos Aires",10},
        {5,"Mario",23,"Zag",8},
        {6,"Nani",24,"Brazil",20},
        {7,"Muller",24,"Berlin",3},
        {8,"Zizo",12,"Porugal",17},
        {9,"dsg",32,"cvbfd",11},
        {10,"fdh",23,"dfhf",7},
        {11,"dsggd",32,"gdgg",18},
        {12,"dsg",32,"cvbfd",11},
        {13,"fdh",23,"dfhf",7},
        {14,"dsggd",32,"gdgg",18},
        {15,"dsggd",32,"gdgg",18}
    };

    int i;
    for(i=0;i<15;i++){
        printf("Student no. %d\n",i+1);
        printf("Roll number : %d\n",S[i].roll_number);
        printf("Name : %s\n",S[i].name);
        printf("Age : %d\n",S[i].age);
        printf("Address : %s\n",S[i].address);
        printf("Marks : %d\n",S[i].marks);
        printf("=============================\n");
    }



    // A function to count number of
    // students with marks less than 12 if the full
    // mark is of 20.
    printf("%d",countFailed(S));



    return 0;
}