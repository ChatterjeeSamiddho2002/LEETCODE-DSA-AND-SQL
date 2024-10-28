int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int longestSquareStreak(int* nums, int numsSize) {
    // If there are less than 2 elements, return -1 immediately
    if (numsSize < 2) return -1;

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Find the maximum value in nums for dynamic allocation
    int maxNum = nums[numsSize - 1];
    int *set = (int*)calloc(maxNum + 1, sizeof(int)); // Allocate based on maxNum

    for (int i = 0; i < numsSize; i++) {
        set[nums[i]] = 1; // Mark existing numbers
    }

    int maxLength = 0;

    for (int i = 0; i < numsSize; i++) {
        int currentNum = nums[i];
        int length = 1; // Start counting the current number
        
        while (1) {
            long long nextSquare = (long long)currentNum * currentNum; // Use long long to avoid overflow
            if (nextSquare <= maxNum && set[nextSquare]) { // Check bounds and existence
                length++; // Increment the length if next square exists
                currentNum = (int)nextSquare; // Move to next square
            } else {
                break; // Break if the next square is not found or out of bounds
            }
        }
        
        if (length > 1) {
            maxLength = (length > maxLength) ? length : maxLength; // Update maxLength if current length is larger
        }
    }

    free(set);
    
    return (maxLength > 1) ? maxLength : -1; // Return the result
}