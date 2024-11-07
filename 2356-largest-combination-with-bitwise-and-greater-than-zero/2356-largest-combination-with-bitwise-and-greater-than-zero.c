int largestCombination(int* candidates, int candidatesSize) {
        int maxCombinationSize = 0;
    
    // Iterate over each bit from 0 to 31 (assuming 32-bit integers)
    for (int bit = 0; bit < 32; bit++) {
        int count = 0;
        
        // Count how many numbers have the current bit set
        for (int i = 0; i < candidatesSize; i++) {
            if ((candidates[i] >> bit) & 1) {
                count++;
            }
        }
        
        // Keep track of the maximum count found
        maxCombinationSize = (count > maxCombinationSize) ? count : maxCombinationSize;
    }
    
    return maxCombinationSize;
}