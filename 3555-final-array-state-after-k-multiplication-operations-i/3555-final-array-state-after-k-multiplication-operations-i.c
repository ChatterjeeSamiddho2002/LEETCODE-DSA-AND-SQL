/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
     // Create a copy of nums for the result
    int* result = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }

    // Perform k operations
    for (int operation = 0; operation < k; operation++) {
        // Find the index of the minimum element
        int minIndex = 0;
        for (int i = 1; i < numsSize; i++) {
            if (result[i] < result[minIndex]) {
                minIndex = i;
            }
        }
        
        // Multiply the minimum element by the multiplier and replace it
        result[minIndex] *= multiplier;
    }
    
    *returnSize = numsSize;  // Set the return size of the array
    return result;           // Return the modified array
}