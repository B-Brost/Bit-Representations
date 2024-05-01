#include <stdio.h>
#include <string.h>

void displayIntAsBits(int i) {
    for (int bit = 31; bit >= 0; --bit) {
        printf("%d", (i >> bit) & 1);
        if (bit % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}


int makeIntFromBits(char* str) {
    int result = 0;
    int length = strlen(str);
    for (int i = length - 1; i > 0; --i) {
        if (str[i] == '1') {
            result |= 1 << (length - 1 - i);
        }
    }
    if (str[0] == '-') {
        result = (~result + 1); // Convert to two's complement for negative numbers
    }
    return result;
}


int main() {
    displayIntAsBits(5);
    displayIntAsBits(-9);
    printf("%d\n", makeIntFromBits("+101"));
    printf("%d\n", makeIntFromBits("-1001"));
    return 0;
}

