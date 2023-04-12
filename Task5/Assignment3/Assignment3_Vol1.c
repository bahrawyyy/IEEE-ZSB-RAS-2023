#include <stdio.h>
#include <stdlib.h>

#define type_t int

typedef struct item{
    type_t Element;
    struct item *next;
}SItem;

SItem *head = NULL;

void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    SItem *current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->Element);
        current = current->next;
    }
    printf("\n");
}

void addItem(type_t value) {
    SItem *newNode = (SItem*)malloc(sizeof(SItem));
    newNode->Element = value;
    newNode->next = head;
    head = newNode;
}

void deleteItem() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    SItem *temp = head;
    head = head->next;
    free(temp);
}

int main() {
    char input;
    int value;

    while (1) {
        printf("Enter '+' to add a node, '-' to delete a node, 'p' to print the list, or 'x' to exit: ");
        scanf(" %c", &input);

        switch (input) {
            case '+':
                printf("Enter a value to add: ");
                scanf("%d", &value);
                addItem(value);
                break;
            case '-':
                deleteItem();
                break;
            case 'p':
                printList();
                break;
            case 'x':
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}