#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    int accountNumber;
    int pin;
    float balance;
} Account;

int loadAccount(int accountNumber, Account* acc);
void saveAccount(Account* acc);
void createAccount();

#endif
