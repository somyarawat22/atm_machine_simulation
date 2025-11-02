#include <stdio.h>
#include "utils.h"

void getFilename(int accountNumber, char* filename) {
    sprintf(filename, "account_%d.txt", accountNumber);
}
