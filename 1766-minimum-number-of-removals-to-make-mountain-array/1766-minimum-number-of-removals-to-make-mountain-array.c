int minimumMountainRemovals(int* nums, int numsSize) {
 if (numsSize < 3) return 0; // Not enough elements to form a mountain

    // Step 1: Calculate LIS from the left
    int lis[numsSize];
    for (int i = 0; i < numsSize; i++) {
        lis[i] = 1; // Each element is a subsequence of length 1
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                lis[i] = (lis[i] > lis[j] + 1) ? lis[i] : (lis[j] + 1);
            }
        }
    }

    // Step 2: Calculate LDS from the right
    int lds[numsSize];
    for (int i = numsSize - 1; i >= 0; i--) {
        lds[i] = 1; // Each element is a subsequence of length 1
        for (int j = numsSize - 1; j > i; j--) {
            if (nums[j] < nums[i]) {
                lds[i] = (lds[i] > lds[j] + 1) ? lds[i] : (lds[j] + 1);
            }
        }
    }

    // Step 3: Find the maximum length of the mountain
    int maxMountainLength = 0;
    for (int i = 1; i < numsSize - 1; i++) {
        if (lis[i] > 1 && lds[i] > 1) {
            maxMountainLength = (maxMountainLength > (lis[i] + lds[i] - 1)) ? maxMountainLength : (lis[i] + lds[i] - 1);
        }
    }

    // Step 4: Calculate minimum removals
    return numsSize - maxMountainLength;   
}