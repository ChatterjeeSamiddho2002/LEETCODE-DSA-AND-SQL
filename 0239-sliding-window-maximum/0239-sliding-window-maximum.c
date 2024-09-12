/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
 if (numsSize == 0 || k == 0) {
         *returnSize = 0;
        return NULL;
    }
    
    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = numsSize - k + 1;

    int deque[numsSize];  // Deque to store indices
    int front = 0, back = -1;

    for (int i = 0; i < numsSize; i++) {
        // Remove elements that are out of this window
        if (front <= back && deque[front] < i - k + 1) {
            front++;
        }

        // Remove elements from the back of deque while they are smaller than the current element
        while (front <= back && nums[deque[back]] <= nums[i]) {
            back--;
        }

        // Add current element at the back of the deque
        deque[++back] = i;

        // The element at the front of the deque is the largest element of the window
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[front]];
        }
    }

    return result;
}