//1.Users can add income and expenses along with descriptions.
//2.The program maintains a balance and transaction history.
//3. Users can view their financial summary, including the current balance and transaction history.
//4.Users can exit the program when they are done.




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a financial transaction
struct Transaction {
    char description[100];
    double amount;
};

int main() {
    int choice;
    double balance = 0.0;
    struct Transaction transactions[100]; // Array to store transactions
    int transactionCount = 0;

    printf("Personal Finance Tracker\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Financial Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add Income
                printf("Enter income description: ");
                char incomeDescription[100];
                scanf(" %[^\n]", incomeDescription);
                printf("Enter income amount: ");
                double incomeAmount;
                scanf("%lf", &incomeAmount);
                transactions[transactionCount].amount = incomeAmount;
                strcpy(transactions[transactionCount].description, incomeDescription);
                transactionCount++;
                balance += incomeAmount;
                printf("Income added successfully!\n");
                break;
            case 2:
                // Add Expense
                printf("Enter expense description: ");
                char expenseDescription[100];
                scanf(" %[^\n]", expenseDescription);
                printf("Enter expense amount: ");
                double expenseAmount;
                scanf("%lf", &expenseAmount);
                transactions[transactionCount].amount = -expenseAmount; // Negative amount for expenses
                strcpy(transactions[transactionCount].description, expenseDescription);
                transactionCount++;
                balance -= expenseAmount;
                printf("Expense added successfully!\n");
                break;
            case 3:
                // View Financial Summary
                printf("Financial Summary:\n");
                printf("Current Balance: %.2lf\n", balance);
                printf("Transaction History:\n");
                for (int i = 0; i < transactionCount; i++) {
                    printf("%s: %.2lf\n", transactions[i].description, transactions[i].amount);
                }
                break;
            case 4:
                // Exit
                printf("Exiting the Personal Finance Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
