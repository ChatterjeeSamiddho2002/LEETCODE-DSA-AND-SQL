int minBitFlips(int start, int goal) {
        int xor = start ^ goal;  // XOR the start and goal to find differing bits
    int count = 0;           // To count the number of bit flips
    
    // Count the number of 1's in xor, i.e., the number of differing bits
    while (xor > 0) {
        count += xor & 1;    // Add 1 if the least significant bit is 1
        xor >>= 1;           // Right shift to check the next bit
    }
    
    return count;
}