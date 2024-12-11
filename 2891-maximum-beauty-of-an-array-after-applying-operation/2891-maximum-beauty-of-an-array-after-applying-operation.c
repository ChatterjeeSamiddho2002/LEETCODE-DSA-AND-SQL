int maximumBeauty(int* nums, int numsSize, int k) {
   int maxValue = 0;

    // Step 1: Find the maximum value in the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxValue) {
            maxValue = nums[i];
        }
    }

    // Step 2: Create an array to track ranges
    int rangeSize = maxValue + 10;
    int* range = (int*)calloc(rangeSize, sizeof(int));

    // Step 3: Mark ranges for each number in the array
    for (int i = 0; i < numsSize; i++) {
        int left = (nums[i] - k > 0) ? nums[i] - k : 0;
        int right = (nums[i] + k < maxValue) ? nums[i] + k + 1 : maxValue + 1;
        range[left]++;
        if (right < rangeSize) {
            range[right]--;
        }
    }

    // Step 4: Calculate prefix sums and find the maximum value
    int result = range[0];
    for (int i = 1; i < rangeSize; i++) {
        range[i] += range[i - 1];
        if (range[i] > result) {
            result = range[i];
        }
    }

    // Step 5: Free the allocated memory and return the result
    free(range);
    return result; 
}