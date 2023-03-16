#include <stdio.h>

struct testOne
{
    int id;
    char name[10];
    char class_id;
};

struct testTwo
{
    char name[10];
    int id;
    char class_id;
};


int main()
{
    printf("Size of the first structure : %d\n",sizeof(struct testOne));
    // The o/p will be 16 as the int will take 4 bytes then 
    // 10 bytes for name, and the char is 1 byte, but it may be
    // padded with one more byte to ensure that size of 
    // structure is multiple of 4


    printf("Size of the second structure : %d\n",sizeof(struct testTwo));
    // In this case name will take 10 bytes, but int should 
    // start with an address of multiple of 4 because of structure
    // padding, to increase performance by optimizing memory access
    // Then 10 bytes + 2 bytes padding + 4 bytes int + 1 byte + 
    // 3 more bytes padding to insure size to be of multiple of 4

}