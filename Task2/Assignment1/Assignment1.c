#include <stdio.h>


int main()
{
    int *p1;
    char *p2;
    long long *p3;

    printf("Before incrementing");

    printf("\n%x",p1);
    printf("\n%x",p2);
    printf("\n%x",p3);

    p1++;
    p2++;
    p3++;

    printf("\nAfter incrementing");

    printf("\nAs p1 points to an int, when it increments, it should points to the next four bytes, so it should increase by 4");
    printf("\n%x",p1);

    printf("\np2 should increase by 1, as it points to char");
    printf("\n%x",p2);

    printf("\np3 should increase by 8, as long long is 8 bytes");
    printf("\n%x",p3);

    return 0;
}