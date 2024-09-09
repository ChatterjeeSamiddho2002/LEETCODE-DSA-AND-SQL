/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
     // Initialize result array and return size
    *returnSize = nums1Size;
    int* result = (int*)malloc(nums1Size * sizeof(int));
    
    // Array to store next greater elements for nums2
    int* nextGreater = (int*)malloc(nums2Size * sizeof(int));
    
    // Initialize stack (to store indexes of nums2)
    int* stack = (int*)malloc(nums2Size * sizeof(int));
    int top = -1; // Stack is empty initially
    
    // Traverse nums2 from right to left to calculate next greater elements
    for (int i = nums2Size - 1; i >= 0; i--) {
        // Pop elements from stack that are less than or equal to the current element
        while (top >= 0 && nums2[stack[top]] <= nums2[i]) {
            top--;
        }
        
        // If stack is not empty, the top element is the next greater element
        if (top >= 0) {
            nextGreater[i] = nums2[stack[top]];
        } else {
            nextGreater[i] = -1; // No next greater element
        }
        
        // Push the current index onto the stack
        stack[++top] = i;
    }
    
    // For each element in nums1, find the corresponding next greater element from nums2
    for (int i = 0; i < nums1Size; i++) {
        // Find index of nums1[i] in nums2
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                result[i] = nextGreater[j];
                break;
            }
        }
    }
    
    // Free the memory used for the nextGreater array and stack
    free(nextGreater);
    free(stack);
    
    return result;
}