#include <stdio.h>

//////////////////////////////////////////////
// Step 1: Customer Information
//////////////////////////////////////////////
void customerInfo(char name[], char cnic[]) {
    printf("\nEnter Customer Name: ");
    scanf(" %[^\n]", name);   // reads full name with spaces

    printf("Enter CNIC Number: ");
    scanf("%s", cnic);
}

//////////////////////////////////////////////
// Step 2: Display Inventory
//////////////////////////////////////////////
void displayInventory(char code[][4], int stock[], int price[], int n) {
    printf("\n--- INVENTORY ---\n");
    printf("Code\tStock\tPrice\n");
    printf("-------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%s  \t%d   \t%d\n", code[i], stock[i], price[i]);
    }
}

//////////////////////////////////////////////
// Helper Function: Compare two strings (manual)
//////////////////////////////////////////////
int compareCode(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return 0;  // not equal
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0')
        return 1;  // both ended → equal
    else
        return 0;
}

//////////////////////////////////////////////
// Step 3: Add Item to Cart
//////////////////////////////////////////////
void addItemToCart(char code[][4], int stock[], int price[], int n,
                   int cartIndex[], int cartQty[], int *cartCount) {

    char productCode[4];
    int quantity;
    int found = 0;

    // Show products first
    displayInventory(code, stock, price, n);

    // Ask user for product code and quantity
    printf("\nEnter Product Code: ");
    scanf("%s", productCode);

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    // Search manually
    for (int i = 0; i < n; i++) {
        if (compareCode(productCode, code[i])) {
            found = 1;

            if (quantity <= stock[i]) {
                printf("\nItem added to cart!\n");

                // Update stock and save in cart
                stock[i] -= quantity;
                cartIndex[*cartCount] = i;
                cartQty[*cartCount] = quantity;
                (*cartCount)++;

                printf("Product %s | Quantity %d | Total = %d\n",
                       code[i], quantity, quantity * price[i]);
            } else {
                printf("\nSorry, only %d items available in stock.\n", stock[i]);
            }
            break;
        }
    }

    if (!found)
        printf("\nInvalid product code!\n");
}

//////////////////////////////////////////////
// Step 4: Display Total Bill
//////////////////////////////////////////////
float displayBill(int cartIndex[], int cartQty[], int cartCount,
                  int price[], char code[][4]) {

    float total = 0;

    printf("\n--- BILL DETAILS ---\n");
    printf("Code\tQty\tPrice\tTotal\n");
    printf("-----------------------------\n");

    for (int i = 0; i < cartCount; i++) {
        int idx = cartIndex[i];
        float itemTotal = cartQty[i] * price[idx];
        total += itemTotal;
        printf("%s\t%d\t%d\t%.2f\n", code[idx], cartQty[i], price[idx], itemTotal);
    }

    printf("-----------------------------\n");
    printf("Total Bill = %.2f\n", total);

    return total;
}

//////////////////////////////////////////////
// Step 5: Apply Promo Code (Eid2025 = 25% off)
//////////////////////////////////////////////
void applyPromo(float total) {
    char promo[20];
    char eidCode[8] = "Eid2025";
    int same = 1, i = 0;
    float finalBill = total;

    printf("\nDo you have a promo code? (Enter code or 'no'): ");
    scanf("%s", promo);

    // Compare manually (no string library)
    while (promo[i] != '\0' || eidCode[i] != '\0') {
        if (promo[i] != eidCode[i]) {
            same = 0;
            break;
        }
        i++;
    }

    if (same == 1) {
        finalBill = total * 0.75; // 25% discount
        printf("\nPromo Applied! 25%% Discount Given.\n");
        printf("Discounted Bill = %.2f\n", finalBill);
    } else {
        printf("\nInvalid or No Promo Code.\n");
        printf("Final Bill = %.2f\n", total);
    }
}

//////////////////////////////////////////////
// MAIN FUNCTION — Menu System
//////////////////////////////////////////////
int main() {
    char name[50], cnic[20];

    // Inventory Data
    char code[4][4] = {"001", "002", "003", "004"};
    int stock[4] = {50, 10, 20, 8};
    int price[4] = {100, 200, 300, 150};
    int n = 4;

    // Cart Data
    int cartIndex[10];
    int cartQty[10];
    int cartCount = 0;

    int choice;
    float totalBill = 0;

    while (1) {
        printf("\n\n====== SUPERMARKET MENU ======\n");
        printf("1. Enter Customer Info\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Apply Promo Code\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            customerInfo(name, cnic);
        else if (choice == 2)
            displayInventory(code, stock, price, n);
        else if (choice == 3)
            addItemToCart(code, stock, price, n, cartIndex, cartQty, &cartCount);
        else if (choice == 4)
            totalBill = displayBill(cartIndex, cartQty, cartCount, price, code);
        else if (choice == 5)
            applyPromo(totalBill);
        else if (choice == 6) {
            printf("\nExiting... Thank you for shopping!\n");
            break;
        } else
            printf("\nInvalid choice! Please try again.\n");
    }

    return 0;
}