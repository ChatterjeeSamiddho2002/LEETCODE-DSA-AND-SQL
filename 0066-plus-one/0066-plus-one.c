/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
        // Iterate from the least significant digit to the most significant digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        // Increment the current digit
        digits[i]++;
        // If the current digit becomes 10, set it to 0 and continue to the next digit
        if (digits[i] < 10) {
            *returnSize = digitsSize; // No change in size
            return digits;
        } else {
            digits[i] = 0;
        }
    }
    // If all digits become 0, we need to add one more digit at the beginning
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1; // Set the most significant digit to 1
    // Copy the original digits to the new array starting from the second digit
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = digits[i - 1];
    }
    *returnSize = digitsSize + 1; // Increase the size by 1
    return result;
}