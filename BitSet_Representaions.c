#include <stdio.h>

typedef unsigned short bitSet; // Defines a new type 'bitSet' as an unsigned short

bitSet makeBitSet(){ // Function to create a new bitset
    bitSet b = 0; // Initializes all bits to 0
    return b; // Returns the new bitset
}

void displayBitSet(bitSet bs){ // Function to display the 16 bits of the bitset
    for(int i = 15; i >= 0; i--){ // Loops over each bit
        printf("%d", (bs >> i) & 1); // Prints the value of the bit
        if(i % 8 == 0) printf(" "); // Adds a space every 8 bits for readability
    }
    printf("\n"); // Prints a newline at the end
}

void setBit(bitSet* bs, int index){ // Function to set a specific bit to 1
    *bs |= 1 << index; // Uses the bitwise OR operator to set the bit
}

void clearBit(bitSet* bs, int index){ // Function to set a specific bit to 0
    *bs &= ~(1 << index); // Uses the bitwise AND operator with the complement of the bit to clear it
}

int bitValue(bitSet bs, int index){ // Function to get the value of a specific bit
    return (bs >> index) & 1; // Uses the bitwise AND operator to get the bit value
}

int main() { // Main function
    bitSet bs = makeBitSet(); // Creates a new bitset
    setBit(&bs, 3); // Sets the 3rd bit to 1
    setBit(&bs, 5); // Sets the 5th bit to 1
    clearBit(&bs, 3); // Sets the 3rd bit back to 0
    displayBitSet(bs); // Displays the bitset
    printf("Bit value at index 5: %d\n", bitValue(bs, 5)); // Prints the value of the 5th bit
    return 0; // Ends the program
}
