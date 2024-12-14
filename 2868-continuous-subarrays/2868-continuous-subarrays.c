long long continuousSubarrays(int* nums, int numsSize){
 long long result = 0;
    int left = 0;

    // Deques for min and max elements
    int minDeque[numsSize], maxDeque[numsSize];
    int minFront = 0, minBack = 0, maxFront = 0, maxBack = 0;

    for (int right = 0; right < numsSize; right++) {
        // Add the current element to the deques
        while (minBack > minFront && nums[minDeque[minBack - 1]] >= nums[right]) {
            minBack--;
        }
        minDeque[minBack++] = right;

        while (maxBack > maxFront && nums[maxDeque[maxBack - 1]] <= nums[right]) {
            maxBack--;
        }
        maxDeque[maxBack++] = right;

        // Shrink the window if the condition is violated
        while (nums[maxDeque[maxFront]] - nums[minDeque[minFront]] > 2) {
            left++;
            if (minDeque[minFront] < left) minFront++;
            if (maxDeque[maxFront] < left) maxFront++;
        }

        // Count the number of valid subarrays ending at 'right'
        result += (right - left + 1);
    }

    return result;
}