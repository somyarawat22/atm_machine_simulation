#include <stdio.h>
#include "auth.h"

#define MAX_ATTEMPTS 3

int authenticate(Account* acc) {
    int pinInput, attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter PIN: ");
        scanf("%d", &pinInput);

        if (pinInput == acc->pin) return 1;

        printf("Incorrect PIN. Try again.\n");
        attempts++;
    }

    return 0;
}
