/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Start from the last digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i] += 1; // Increment the digit and return
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0; // Set the current digit to 0 and carry over
    }
    
    // If we reached here, it means we need to add a new digit at the front
    int* newDigits = (int*)malloc((digitsSize + 1) * sizeof(int));
    newDigits[0] = 1; // Set the first digit to 1
    for (int i = 1; i < digitsSize + 1; i++) {
        newDigits[i] = 0; // Set the rest to 0
    }
    
    *returnSize = digitsSize + 1;
    return newDigits;
}