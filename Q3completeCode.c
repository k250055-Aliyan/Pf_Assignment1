#include <stdio.h>

// Define bit masks for readability
#define POWER 1        // Bit 0 (0001)
#define OVERLOAD 2     // Bit 1 (0010)
#define MAINTENANCE 4  // Bit 2 (0100)

// Function to update a sector’s status
void updateSector(int grid[5][5], int rows, int cols) {
    int r, c, choice, action;
    printf("Enter sector row (0-%d): ", rows - 1);
    scanf("%d", &r);
    printf("Enter sector column (0-%d): ", cols - 1);
    scanf("%d", &c);

    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("\nChoose flag to update:\n");
    printf("1. Power\n");
    printf("2. Overload\n");
    printf("3. Maintenance\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("1. Set (Turn ON)\n2. Clear (Turn OFF)\nEnter your action: ");
    scanf("%d", &action);

    int mask = 0;
    if (choice == 1) mask = POWER;
    else if (choice == 2) mask = OVERLOAD;
    else if (choice == 3) mask = MAINTENANCE;
    else {
        printf("Invalid flag choice!\n");
        return;
    }

    if (action == 1)
        grid[r][c] |= mask; 
    else if (action == 2)
        grid[r][c] &= ~mask; 
    else
        printf("Invalid action!\n");

    printf("Sector status updated successfully!\n");
}

// Function to query a sector’s current status
void querySector(int grid[5][5], int rows, int cols) {
    int r, c;
    printf("Enter sector row (0-%d): ", rows - 1);
    scanf("%d", &r);
    printf("Enter sector column (0-%d): ", cols - 1);
    scanf("%d", &c);

    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        printf("Invalid coordinates!\n");
        return;
    }

    int value = grid[r][c];

    printf("\nSector (%d, %d) Status:\n", r, c);
    printf("Power: %s\n", (value & POWER) ? "ON" : "OFF");
    printf("Overload: %s\n", (value & OVERLOAD) ? "YES" : "NO");
    printf("Maintenance: %s\n\n", (value & MAINTENANCE) ? "Required" : "Not Required");
}


void runDiagnostic(int grid[5][5], int rows, int cols) {
    int overloadCount = 0, maintenanceCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] & OVERLOAD)
                overloadCount++;
            if (grid[i][j] & MAINTENANCE)
                maintenanceCount++;
        }
    }

    printf("\nSystem Diagnostic Report:\n");
    printf("Total Overloaded Sectors: %d\n", overloadCount);
    printf("Total Maintenance Required: %d\n\n", maintenanceCount);
}

// Main program
int main() {
    int grid[5][5] = {0}; // 5x5 grid initialized to 0
    int choice;

    do {
        printf("\n--- IESCO Power Grid Monitoring ---\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateSector(grid, 5, 5);
                break;
            case 2:
                querySector(grid, 5, 5);
                break;
            case 3:
                runDiagnostic(grid, 5, 5);
                break;
            case 4:
                printf("Exiting program... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
