#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store smartwatch details
typedef struct {
    int id;
    char name[50];
    int quantity;
} Smartwatch;

// Function to initialize inventory dynamically
Smartwatch* initializeInventory(int size) {
    Smartwatch* watches = (Smartwatch*)malloc(size * sizeof(Smartwatch));
    if (watches == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        watches[i].id = i;
        printf("Enter name of watch %d: ", i);
        scanf(" %[^\n]", watches[i].name); // Reads a string with spaces
        printf("Enter quantity available for %s: ", watches[i].name);
        scanf("%d", &watches[i].quantity);
    }

    return watches;
}

// Function to display inventory
void displayInventory(Smartwatch* watches, int size) {
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\t\tPrice\tQuantity\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%-20s $%.2f\t%d\n", watches[i].id, watches[i].name, watches[i].quantity);
    }
}

// Function to update inventory
void updateInventory(Smartwatch* watches, int size, int id, int quantitySold) {
    if (id < 0 || id >= size) {
        printf("Invalid watch ID!\n");
        return;
    }
    
    if (watches[id].quantity >= quantitySold) {
        watches[id].quantity -= quantitySold;
        printf("Purchase successful! %d units of %s sold.\n", quantitySold, watches[id].name);
    } else {
        printf("Insufficient stock! Only %d units available.\n", watches[id].quantity);
    }
}

int main() {
    int numWatches, choice, id, quantitySold;
    
    printf("Enter the number of smartwatches to store: ");
    scanf("%d", &numWatches);

    Smartwatch* watches = initializeInventory(numWatches);

    while (1) {
        printf("\n1. Display Inventory\n");
        printf("2. Purchase a Smartwatch\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayInventory(watches, numWatches);
                break;
            case 2:
                printf("Enter Watch ID to purchase: ");
                scanf("%d", &id);
                printf("Enter quantity to purchase: ");
                scanf("%d", &quantitySold);
                updateInventory(watches, numWatches, id, quantitySold);
                break;
            case 3:
                free(watches); // Free dynamically allocated memory
                printf("Memory freed. Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}





