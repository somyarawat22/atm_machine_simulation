#include <stdio.h>
#include "account.h"
#include "auth.h"
#include "transaction.h"

int main() {
    int choice, accountNumber;
    Account currentAccount;

    while (1) {
        printf("\n---- Welcome to ATM ----\n");
        printf("1. Login to Account\n");
        printf("2. Create New Account\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Account Number: ");
            scanf("%d", &accountNumber);

            if (!loadAccount(accountNumber, &currentAccount)) {
                printf("Account not found.\n");
                continue;
            }

            if (!authenticate(&currentAccount)) {
                printf("Authentication failed. Returning to main menu...\n");
                continue;
            }

            int transChoice;
            do {
                printf("\n---- ATM Menu ----\n");
                printf("1. Balance Inquiry\n");
                printf("2. Deposit\n");
                printf("3. Withdraw\n");
                printf("4. Logout\n");
                printf("Choose an option: ");
                scanf("%d", &transChoice);

                switch (transChoice) {
                    case 1:
                        balanceInquiry(&currentAccount);
                        break;
                    case 2:
                        deposit(&currentAccount);
                        break;
                    case 3:
                        withdraw(&currentAccount);
                        break;
                    case 4:
                        printf("Logging out...\n");
                        break;
                    default:
                        printf("Invalid option.\n");
                }
            } while (transChoice != 4);
        }

        else if (choice == 2) {
            createAccount();
        }

        else if (choice == 3) {
            printf("Thank you for using the ATM. Goodbye!\n");
            break;
        }

        else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
