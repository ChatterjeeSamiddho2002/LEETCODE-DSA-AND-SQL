/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    // Result array to store the next greater elements
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // Stack to store indices of elements
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1; // Stack is empty initially
    
    // Initialize the result array with -1 (for cases where no greater element exists)
    for (int i = 0; i < numsSize; i++) {
        result[i] = -1;
    }
    
    // Traverse the array twice to simulate circular behavior
    for (int i = 0; i < 2 * numsSize; i++) {
        // Get the actual index in the array
        int index = i % numsSize;
        
        // Pop elements from the stack if the current element is greater
        while (top >= 0 && nums[stack[top]] < nums[index]) {
            result[stack[top--]] = nums[index];
        }
        
        // Only push the index onto the stack in the first pass
        if (i < numsSize) {
            stack[++top] = index;
        }
    }
    
    // Free the stack memory
    free(stack);
    
    return result;    
}