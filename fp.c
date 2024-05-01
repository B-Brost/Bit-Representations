#include <stdio.h>
#include <string.h>
#include <math.h>

typedef union floatU {
    unsigned int bits;
    float theFloat;
} floatU;

void displayFloatAsBits(float f) {
    floatU u;
    u.theFloat = f;

    // Displaying the float's bits
    for (int bit = 31; bit >= 0; --bit) {
        printf("%d", (u.bits >> bit) & 1);
        if (bit % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

float makeFloatFromBits(char* str) {
    int sign = 1;
    if (*str == '-') {
        sign = -1;
    }
    str++;

    // Calculate the integer part
    float integerPart = 0.0f;
    while (*str != '.') {
        integerPart = integerPart * 2 + (*str - '0');
        str++;
    }
    str++; // Skip the '.'

    // Calculate the fractional part
    float fractionalPart = 0.0f;
    float weight = 0.5f;
    while (*str != '\0') {
        if (*str == '1') {
            fractionalPart += weight;
        }
        weight *= 0.5f;
        str++;
    }

    // Construct the float
    float result = sign * (integerPart + fractionalPart);
    return result;
}

int main() {
    float result = makeFloatFromBits("-101.1101");
    printf("%f\n", result);  // Output: -5.812500
    result = makeFloatFromBits("+101.1101");
    printf("%f\n", result);  // Output: 5.812500
    displayFloatAsBits(-5.8125);  
    return 0;
}

