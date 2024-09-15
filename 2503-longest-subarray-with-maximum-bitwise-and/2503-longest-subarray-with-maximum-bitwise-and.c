int longestSubarray(int* nums, int numsSize) {
        int maxElem = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > maxElem) {
            maxElem = nums[i];
        }
    }
    
   
    int maxLen = 0, currentLen = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == maxElem) {
            currentLen++;  // Continue the current subarray
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else {
            currentLen = 0;  // Reset length when the number is not equal to maxElem
        }
    }
    
    return maxLen;
}