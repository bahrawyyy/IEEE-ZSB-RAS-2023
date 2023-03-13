#include<stdio.h>
#include "Prob2.h"

// This extern variable is defined in Prob2.h
extern int externVar;

void counterStatic(void)
{
   // static updates the value among 
   // each function call
   static int count = 0;
   count++;
   printf("%d\n",count);
}

void counterAuto(void)
{
   // Doesn't matter if we wrote auto
   // before variable or not
   // same result
   auto int count = 0;
   count++;
   printf("%d\n",count);
}


int main()
{
    printf("static updates the value among\neach function call\n");
    counterStatic();
    counterStatic();
    counterStatic();
    printf("auto are the same as local variables\nThe stack of the function contains it will be deleted when returning from the function\nso, each time the value will be the same\n");
    counterAuto();
    counterAuto();
    counterAuto();
    printf("Putting the keyword register should put this variable inside a CPU register,\nbut it isn't our call, the compiler is the one who decide if it will be put inside a register or not based on if there are any available registers that are not used\n");
    
    register int x = 4;
    printf("%d\n",x);
    
    externVar = 7;
    printf("Putting the keyword extern, this is just a declaration, means that the definition of this variable is inside another file, it's the linker task to link between them, and if not defined in another file it will produce a linker error\n");
    printf("%d",externVar);
  
    return 0;
}
