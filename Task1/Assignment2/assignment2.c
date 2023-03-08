#include <stdio.h>





int main()
{

    int x=3,y=7,z=14;
    int *p,*q,*r;
    p = &x;
    q = &y;
    r = &z;
    printf("x = %d\n",x);
    printf("y = %d\n",y);
    printf("z = %d\n",z);
    printf("p = %d\n",p);
    printf("q = %d\n",q);
    printf("r = %d\n",r);
    printf("*p = %d\n",*p);
    printf("*q = %d\n",*q);
    printf("*r = %d\n",*r);
    printf("Swapping Pointers\n");
    r = p;
    p = q;
    q = r;
    printf("x = %d\n",x);
    printf("y = %d\n",y);
    printf("z = %d\n",z);
    printf("p = %d\n",p);
    printf("q = %d\n",q);
    printf("r = %d\n",r);
    printf("*p = %d\n",*p);
    printf("*q = %d\n",*q);
    printf("*r = %d\n",*r);


    return 0;
}