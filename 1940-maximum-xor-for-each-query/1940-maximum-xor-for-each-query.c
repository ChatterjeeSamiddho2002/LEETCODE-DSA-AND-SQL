/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
        int n = numsSize;
    int maxValue = (1 << maximumBit) - 1;  // This is 2^maximumBit - 1
    int* result = (int*)malloc(sizeof(int) * n);
    *returnSize = n;  // Set the size of the return array
    
    int currentXor = 0;
    
    // First pass: Calculate the cumulative XOR of the entire array
    for (int i = 0; i < n; i++) {
        currentXor ^= nums[i];
    }

    // Second pass: Calculate the result for each query
    for (int i = 0; i < n; i++) {
        result[i] = currentXor ^ maxValue;  // Maximize XOR for current query
        currentXor ^= nums[n - 1 - i];      // Update currentXor by removing the last element (simulate removing it)
    }

    return result;
}

// Helper function to print arrays (for testing)
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
