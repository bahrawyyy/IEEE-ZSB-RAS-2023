#include <stdio.h>

struct shops{   
    char name[10];
    char location[10];
};

struct product_info
{
    int id;
    float price;
    int quantity;
};

struct category
{
    int id;
    int products_num;
};

typedef union database{
    struct shops Shop;
    struct product_info Product;
    struct category Category;
}Udatabase;

typedef struct ssdatabase{
    struct shops Shop;
    struct product_info Product;
    struct category Category;
}Sdatabase;

int main()
{
    Udatabase DataBase_U;
    printf("Size of union : %d\n",sizeof(DataBase_U));
    printf("size of struct shops : %d\n",sizeof(DataBase_U.Shop));
    printf("size of struct product_info : %d\n",sizeof(DataBase_U.Product));
    printf("size of struct category : %d\n",sizeof(DataBase_U.Category));
    
    // Union is a shared memory, its size will be the size of its
    // largest member

    Sdatabase DataBase_S;
    printf("Size of Structure : %d\n",sizeof(DataBase_S));
    // Now it differs as the structure will be stored in memory
    // sequentialy and the size is the sum of the sizes of 
    // its members + some padding bytes 
    // and may differ a little bit if we deactivated padding
    // The size = 20 + 12 + 8 = 40



}