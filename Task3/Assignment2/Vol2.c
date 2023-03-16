#include <stdio.h>


typedef struct info{
    char name[10];
    int age;
}Sinfo;

int main()
{
    Sinfo Person1 = {"Abdalla",22};

    Sinfo *P_Person1;
    P_Person1 = &Person1;

    printf("Name : %s\nage : %d",P_Person1->name,P_Person1->age);


}