#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "utils.h"

int loadAccount(int accountNumber, Account* acc) {
    char filename[100];
    getFilename(accountNumber, filename);

    FILE* file = fopen(filename, "r");
    if (!file) return 0;

    fscanf(file, "%d %d %f", &acc->accountNumber, &acc->pin, &acc->balance);
    fclose(file);
    return 1;
}

void saveAccount(Account* acc) {
    char filename[100];
    getFilename(acc->accountNumber, filename);

    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error saving account data.\n");
        return;
    }

    fprintf(file, "%d\n%d\n%.2f\n", acc->accountNumber, acc->pin, acc->balance);
    fclose(file);
}

void createAccount() {
    Account newAcc;
    char filename[100];

    printf("Enter new Account Number: ");
    scanf("%d", &newAcc.accountNumber);
    getFilename(newAcc.accountNumber, filename);

    FILE* check = fopen(filename, "r");
    if (check) {
        printf("Account already exists.\n");
        fclose(check);
        return;
    }

    do {
        printf("Set 4-digit PIN: ");
        scanf("%d", &newAcc.pin);
    } while (newAcc.pin < 1000 || newAcc.pin > 9999);

    printf("Enter initial deposit amount: ");
    scanf("%f", &newAcc.balance);

    saveAccount(&newAcc);
    printf("Account created successfully!\n");
}
