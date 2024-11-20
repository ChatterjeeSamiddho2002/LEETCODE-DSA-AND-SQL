long long maximumSubarraySum(int* nums, int numsSize, int k) {
    if (numsSize < k) return 0;  // If there are not enough elements to form a subarray of length k
    
    long long maxSum = 0;  // To store the maximum sum found
    long long currentSum = 0;  // Sum of the current window
    int left = 0;  // Left pointer of the sliding window
    int* freq = (int*)calloc(100001, sizeof(int));  // Frequency map for elements in the window
    int distinctCount = 0;  // To track the number of distinct elements in the window

    for (int right = 0; right < numsSize; ++right) {
        // Add the current element to the window
        if (freq[nums[right]] == 0) {
            distinctCount++;  // This is a new distinct element
        }
        freq[nums[right]]++;
        currentSum += nums[right];

        // Once the window reaches size k, check the conditions
        if (right - left + 1 == k) {
            if (distinctCount == k) {  // Check if all elements in the window are distinct
                maxSum = (currentSum > maxSum) ? currentSum : maxSum;  // Update max sum
            }

            // Slide the window by removing the leftmost element
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                distinctCount--;  // An element was completely removed, so it's no longer distinct
            }
            currentSum -= nums[left];
            left++;  // Move the left pointer to the right
        }
    }

    free(freq);  // Free the frequency map
    return maxSum;  // Return the maximum sum found 
}