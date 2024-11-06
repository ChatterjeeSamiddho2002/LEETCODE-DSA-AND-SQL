int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += (num & 1);
        num >>= 1;
    }
    return count;
}

bool canSortArray(int* nums, int numsSize) {
    int pmax = INT_MIN; // Previous max, starts as very small
    int cmin = INT_MAX; // Current min, starts as very large
    int cmax = INT_MIN; // Current max, starts as very small
    int pcnt = -1;      // Previous set bits count, starts as invalid

    for (int i = 0; i < numsSize; i++) {
        int ccnt = countSetBits(nums[i]); // Get set bits count of current number
        if (pcnt == ccnt) {
            // Same set bits count, update the current range
            if (nums[i] < cmin) cmin = nums[i];
            if (nums[i] > cmax) cmax = nums[i];
        } else {
            // If current range is not sorted
            if (cmin < pmax) return false;

            // Update previous max and set up for the new set of numbers
            pmax = cmax;
            cmin = cmax = nums[i];
            pcnt = ccnt;
        }
    }

    // Final check for the last segment of numbers
    return cmin >= pmax;
}