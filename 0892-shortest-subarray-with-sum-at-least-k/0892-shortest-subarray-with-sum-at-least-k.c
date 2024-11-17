int shortestSubarray(int* nums, int numsSize, int k) {
     // Step 1: Compute the prefix sum array using long long for larger sums
    long long* prefix = (long long*)malloc((numsSize + 1) * sizeof(long long));
    prefix[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // Step 2: Use a deque to find the shortest subarray with sum >= k
    int* deque = (int*)malloc((numsSize + 1) * sizeof(int)); // deque for indices
    int front = 0, rear = 0;
    int minLength = INT_MAX;

    for (int i = 0; i <= numsSize; i++) {
        // Check if we have a valid subarray
        while (front < rear && prefix[i] - prefix[deque[front]] >= k) {
            minLength = (minLength < i - deque[front]) ? minLength : i - deque[front];
            front++; // Remove from deque
        }

        // Maintain the deque - remove elements that are not useful
        while (front < rear && prefix[i] <= prefix[deque[rear - 1]]) {
            rear--; // Pop from deque
        }

        deque[rear++] = i; // Add current index to deque
    }

    free(prefix);
    free(deque);

    return minLength == INT_MAX ? -1 : minLength;
}