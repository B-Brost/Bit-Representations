#include <stdio.h>
#include <string.h>
#include <math.h>

typedef union floatU { // Defines a union to hold a float and its corresponding bit representation
    unsigned int bits; // The bit representation
    float theFloat; // The float
} floatU;

void displayFloatAsBits(float f) { // Function to display the bit representation of a float
    floatU u;
    u.theFloat = f; // Assigns the float to the union

    // Loops over each bit from most significant to least significant
    for (int bit = 31; bit >= 0; --bit) {
        printf("%d", (u.bits >> bit) & 1); // Prints the value of the bit
        if (bit % 8 == 0) {
            printf(" "); // Adds a space every 8 bits for readability
        }
    }
    printf("\n"); // Prints a newline at the end
}

float makeFloatFromBits(char* str) { // Function to convert a binary string to a float
    int sign = 1; // The sign of the number
    if (*str == '-') {
        sign = -1; // If the string starts with '-', the number is negative
    }
    str++; // Skips the sign character

    // Calculates the integer part of the number
    float integerPart = 0.0f;
    while (*str != '.') {
        integerPart = integerPart * 2 + (*str - '0'); // Multiplies the current total by 2 and adds the current digit
        str++; // Moves to the next character
    }
    str++; // Skips the '.'

    // Calculates the fractional part of the number
    float fractionalPart = 0.0f;
    float weight = 0.5f; // The weight of the current digit
    while (*str != '\0') {
        if (*str == '1') {
            fractionalPart += weight; // Adds the weight to the total if the digit is '1'
        }
        weight *= 0.5f; // Halves the weight for the next digit
        str++; // Moves to the next character
    }

    // Constructs the float from the integer and fractional parts and the sign
    float result = sign * (integerPart + fractionalPart);
    return result; // Returns the result
}

int main() { // Main function
    float result = makeFloatFromBits("-101.1101"); // Converts the binary string to a float
    printf("%f\n", result);  // Outputs: -5.812500
    result = makeFloatFromBits("+101.1101"); // Converts another binary string to a float
    printf("%f\n", result);  // Outputs: 5.812500
    displayFloatAsBits(-5.8125);  // Displays the bit representation of a float
    return 0; // Ends the program
}
