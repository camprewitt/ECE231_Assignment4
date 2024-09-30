#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index) {
    item_list[index].price = price;
    item_list[index].sku = malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);
    item_list[index].category = malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);
    item_list[index].name = malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
    }
    free(item_list);
}

double average_price(Item *item_list, int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += item_list[i].price;
    }
    return total / size;
}

void print_items(Item *item_list, int size) {
    for (int i = 0; i < size; i++) {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
        printf("###############\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <SKU>\n", argv[0]);
        return 1;
    }

    int size = 5;
    Item *item_list = malloc(size * sizeof(Item));

    // Coder: Add items to the list here
    add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 2.50, "12345", "snack", "bbq chips", 2);
    add_item(item_list, 4.75, "67976", "beverage", "pepsi", 3);
    add_item(item_list, 6.00, "55243", "fruits", "apples", 4);

    // Print all items
    print_items(item_list, size);

    // Calculate and print average price
    double avg_price = average_price(item_list, size);
    printf("average price of items = %f\n", avg_price);

    // Search for item by SKU
    int search_sku = atoi(argv[1]);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (atoi(item_list[i].sku) == search_sku) {
            printf("###############\n");
            printf("item name = %s\n", item_list[i].name);
            printf("item sku = %s\n", item_list[i].sku);
            printf("item category = %s\n", item_list[i].category);
            printf("item price = %f\n", item_list[i].price);
            printf("###############\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("item not found\n");
    }

    // Free allocated memory
    free_items(item_list, size);

    return 0;
}
