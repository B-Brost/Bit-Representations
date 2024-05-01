#include <stdio.h>
#include <string.h>

void displayIntAsBits(int i) { // Function to display the bit representation of an integer
    for (int bit = 31; bit >= 0; --bit) { // Loops over each bit from most significant to least significant
        printf("%d", (i >> bit) & 1); // Prints the value of the bit
        if (bit % 8 == 0) {
            printf(" "); // Adds a space every 8 bits for readability
        }
    }
    printf("\n"); // Prints a newline at the end
}

int makeIntFromBits(char* str) { // Function to convert a binary string to an integer
    int result = 0; // The result integer
    int length = strlen(str); // The length of the string
    for (int i = length - 1; i > 0; --i) { // Loops over each character from right to left
        if (str[i] == '1') {
            result |= 1 << (length - 1 - i); // If the character is '1', sets the corresponding bit in the result
        }
    }
    if (str[0] == '-') { // If the string starts with '-', the number is negative
        result = (~result + 1); // Converts the result to two's complement
    }
    return result; // Returns the result
}

int main() { // Main function
    displayIntAsBits(5); // Displays the bit representation of 5
    displayIntAsBits(-9); // Displays the bit representation of -9
    printf("%d\n", makeIntFromBits("+101")); // Converts the binary string "+101" to an integer and prints it
    printf("%d\n", makeIntFromBits("-1001")); // Converts the binary string "-1001" to an integer and prints it
    return 0; // Ends the program
}

