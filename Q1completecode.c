#include <stdio.h>
#include <string.h>

// Function prototypes
void AddNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count);
void ProcessSale(int isbns[], int quantities[], int count);
void LowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count);

int main() {
    // Step 1: Declare arrays and count
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;   // Tracks how many books are currently in inventory

    int choice;

    // Step 2: Main menu loop
    while(1) {
        printf("\n--- Liberty Books Inventory Menu ---\n");
        printf("1. Add New Book\n");
        printf("2. Process Sale\n");
        printf("3. Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                AddNewBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                ProcessSale(isbns, quantities, count);
                break;
            case 3:
                LowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;  // Exit program
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}

// ------------------ Step 3: Add New Book ------------------
void AddNewBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    if (*count >= 100) {
        printf("Inventory full! Cannot add more books.\n");
        return;
    }

    int newISBN;
    char newTitle[50];
    float newPrice;
    int newQuantity;

    printf("Enter ISBN: ");
    scanf("%d", &newISBN);

    // Check for duplicate ISBN
    for (int i = 0; i < *count; i++) {
        if (isbns[i] == newISBN) {
            printf("Book with this ISBN already exists!\n");
            return;
        }
    }

    printf("Enter Title: ");
    scanf(" %[^\n]", newTitle);  // Read string with spaces

    printf("Enter Price: ");
    scanf("%f", &newPrice);

    printf("Enter Quantity: ");
    scanf("%d", &newQuantity);

    // Add book to arrays
    isbns[*count] = newISBN;
    strcpy(titles[*count], newTitle);
    prices[*count] = newPrice;
    quantities[*count] = newQuantity;

    (*count)++;  // Increment count → next book will be stored at next index

    printf("Book added successfully!\n");
}

// ------------------ Step 4: Process Sale ------------------
void ProcessSale(int isbns[], int quantities[], int count) {
    int sellISBN, sellQuantity;
    int found = 0;  // flag to check if book exists

    printf("Enter ISBN of the book to sell: ");
    scanf("%d", &sellISBN);
    printf("Enter quantity to sell: ");
    scanf("%d", &sellQuantity);

    // Search for the book
    for (int i = 0; i < count; i++) {
        if (isbns[i] == sellISBN) {
            found = 1;  // Book found
            if (quantities[i] >= sellQuantity) {
                quantities[i] -= sellQuantity;  // Subtract sold quantity
                printf("Sale successful. Remaining quantity: %d\n", quantities[i]);
            } else {
                printf("Not enough stock! Available quantity: %d\n", quantities[i]);
            }
            break;
        }
    }

    if (!found) {
        printf("Book with ISBN %d not found in inventory.\n", sellISBN);
    }
}

// ------------------ Step 5: Low Stock Report ------------------
void LowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int found = 0;  // flag to check if any low-stock books exist

    printf("\n--- Low Stock Report (Quantity < 5) ---\n");

    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No low-stock books found.\n");
    }
}
