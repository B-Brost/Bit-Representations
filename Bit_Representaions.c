#include <stdio.h>

typedef unsigned short bitSet;

bitSet makeBitSet(){ // Create a new bitset
    bitSet b = 0;
    return b;
}

void displayBitSet(bitSet bs){ // Displays the 16 bits of the bitset to the screen
    for(int i = 15; i >= 0; i--){
        printf("%d", (bs >> i) & 1);
        if(i % 8 == 0) printf(" ");
    }
    printf("\n");
}


void setBit(bitSet* bs, int index){ // Sets bit 'index' of the bitset to 1
    *bs |= 1 << index;
}

void clearBit(bitSet* bs, int index){ // Sets bit 'index' of the bitset to 0
    *bs &= ~(1 << index);
}

int bitValue(bitSet bs, int index){ // Returns the value of the bit at 'index'
    return (bs >> index) & 1;
}


int main() {
    bitSet bs = makeBitSet();
    setBit(&bs, 3);
    setBit(&bs, 5);
    clearBit(&bs, 3);
    displayBitSet(bs);
    printf("Bit value at index 5: %d\n", bitValue(bs, 5));
    return 0;
}

