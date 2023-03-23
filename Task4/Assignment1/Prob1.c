#include <stdio.h>


// Here roll_number will take the first 4 bits of the first byte
// Then age will take a full byte
// Then marks will take 3 bits of the third byte
// which results in 3 bytes + 1 byte for padding
// 4 bytes for each pointer
// Then the total size is expected to be 4 + 4 + 4 = 12

typedef struct student_info{
    unsigned char roll_number:4;
    unsigned char age:8;
    unsigned char marks:3;
    char *name;
    char *address;
}Sinfo;

// Why unsigned ? 
// To avoid 1 in MSB which will results in 
// a completely different value than we expect

void printStudent(Sinfo s[],int size);

int main()
{
    Sinfo students[15] = {
        {0,21,2,"Ahmed","Egypt"},
        {1,22,3,"Leo","Argentina"},
        {2,23,1,"Abdalla","Egypt"},
        {3,18,0,"Ahmed","Egypt"},
        {4,19,3,"Mohamed","Qatar"},
        {5,17,4,"Mahmoud","Saudi"},
        {6,15,3,"Karem","USA"},
        {7,22,2,"John","UAE"},
        {8,21,1,"Memo","Bangaladish"},
        {9,23,0,"KE","USA"},
        {10,22,2,"LEO","UAE"},
        {11,17,3,"ANTONYO","USA"},
        {12,18,1,"FRED","Brazil"},
        {13,19,3,"Messe","USA"},
        {14,17,4,"Mss","UAE"}
    };

    // Expected to be 15*12 = 180
    printf("Total Size : %d\n",sizeof(students));
    // So, instead of passing each element (By value)
    // We're gonna pass just a pointer (By reference)
    // which will reflects the calling time significantly.
    
    printStudent(students,15);

    return 0;
}


void printStudent(Sinfo s[],int size)
{
    int i;
    printf("Students Info.\n");
    for(i=0;i<size;i++){
        printf("Roll number : %d\n",s[i].roll_number);
        printf("Name : %s\n",s[i].name);
        printf("Addres : %s\n",s[i].address);
        printf("Age : %d\n",s[i].age);
        printf("Marks : %d\n",s[i].marks);
        printf("===========================\n");
    }
    
}