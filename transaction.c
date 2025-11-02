#include <stdio.h>
#include "transaction.h"
#include "account.h"

void balanceInquiry(Account* acc) {
    printf("Current Balance: Rs%.2f\n", acc->balance);
}

void deposit(Account* acc) {
    float amount;
    printf("Enter amount to deposit: Rs");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    acc->balance += amount;
    saveAccount(acc);
    printf("Deposit successful.\n");
}

void withdraw(Account* acc) {
    float amount;
    printf("Enter amount to withdraw: Rs");
    scanf("%f", &amount);

    if (amount <= 0 || amount > acc->balance) {
        printf("Invalid or insufficient balance.\n");
        return;
    }

    acc->balance -= amount;
    saveAccount(acc);
    printf("Withdrawal successful.\n");
}
