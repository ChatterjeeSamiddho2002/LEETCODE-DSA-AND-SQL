/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void calculateSum(int* nums, int numsSize, int k, int* windowSum) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    windowSum[0] = sum;
    
    for (int i = 1; i <= numsSize - k; i++) {
        sum = sum - nums[i - 1] + nums[i + k - 1];
        windowSum[i] = sum;
    }
}
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
     int* result = (int*)malloc(3 * sizeof(int));
    *returnSize = 3;

    int windowSum[numsSize - k + 1];
    calculateSum(nums, numsSize, k, windowSum);
    
    int left[numsSize - k + 1];
    int right[numsSize - k + 1];
    
    // Compute left array (max subarray sum from left)
    int best = 0;
    for (int i = 0; i < numsSize - k + 1; i++) {
        if (windowSum[i] > windowSum[best]) {
            best = i;
        }
        left[i] = best;
    }
    
    // Compute right array (max subarray sum from right)
    best = numsSize - k;
    for (int i = numsSize - k; i >= 0; i--) {
        if (windowSum[i] >= windowSum[best]) {
            best = i;
        }
        right[i] = best;
    }
    
    // Calculate the maximum sum of three subarrays
    int maxSum = 0;
    for (int j = k; j <= numsSize - 2 * k; j++) {
        int i = left[j - k];
        int l = right[j + k];
        int currentSum = windowSum[i] + windowSum[j] + windowSum[l];
        
        if (currentSum > maxSum) {
            maxSum = currentSum;
            result[0] = i;
            result[1] = j;
            result[2] = l;
        }
    }
    
    return result;
}