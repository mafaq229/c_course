#include <stdio.h>
#include <stdlib.h>

struct item {
    char *itemName;
    int quantity;
    float price;
    float amount;
};

void readItem(struct item *item) {
    printf("Enter item name: ");
    scanf("%s", item->itemName);
    printf("Enter quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter price: ");
    scanf("%f", &item->price);

    item->amount = (float)item->quantity * (float)item->price;
}

void printItem(struct item *item) {
    printf("Item name: %s\n", item->itemName);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2f\n", item->price);
    printf("Amount: %.2f\n", item->amount);
}

int main() {
    struct item item1, *ptr;
    ptr = &item1;

    ptr->itemName = (char *)malloc(30 * sizeof(char));

    if (ptr->itemName == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }

    readItem(ptr);
    printItem(ptr);

    return 0;
}