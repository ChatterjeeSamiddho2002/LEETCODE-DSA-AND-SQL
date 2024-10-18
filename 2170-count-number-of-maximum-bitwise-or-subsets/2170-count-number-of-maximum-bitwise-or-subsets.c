int countMaxOrSubsets(int* nums, int numsSize) {
        int maxOr = 0;

    // Step 1: Calculate the maximum possible bitwise OR
    for (int i = 0; i < numsSize; i++) {
        maxOr |= nums[i];
    }

    // Step 2: Count subsets that yield the maximum OR
    int count = 0;

    // Total number of subsets is 2^n (where n is numsSize)
    int totalSubsets = 1 << numsSize; // 2^numsSize

    for (int i = 1; i < totalSubsets; i++) { // Start from 1 to avoid empty subset
        int currentOr = 0;

        for (int j = 0; j < numsSize; j++) {
            // Check if the j-th bit is set in i
            if (i & (1 << j)) {
                currentOr |= nums[j];
            }
        }

        // If the current OR equals the max OR, increment count
        if (currentOr == maxOr) {
            count++;
        }
    }

    return count;
}