int minimumSize(int* nums, int numsSize, int maxOperations) {
    int low = 1, high = 0;
    
    // Step 1: Determine the maximum value in the nums array (high boundary for binary search)
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > high) {
            high = nums[i];
        }
    }

    // Step 2: Perform binary search
    while (low < high) {
        int mid = low + (high - low) / 2;
        int operations = 0;
        
        // Step 3: Check if we can achieve 'mid' as the max bag size with at most 'maxOperations' splits
        for (int i = 0; i < numsSize; i++) {
            // Calculate the number of splits needed for nums[i] to ensure each bag has at most 'mid' balls
            operations += (nums[i] - 1) / mid;  // equivalent to ceil(nums[i] / mid) - 1
            if (operations > maxOperations) {
                break;
            }
        }
        
        // Step 4: Adjust binary search bounds
        if (operations <= maxOperations) {
            high = mid;  // mid is a valid penalty, try smaller values
        } else {
            low = mid + 1;  // mid is too small, need to increase penalty
        }
    }

    return low;
}