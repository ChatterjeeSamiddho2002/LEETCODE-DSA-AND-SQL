#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxWidthRamp(int* nums, int numsSize) {
     int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = 0;
    
    // Build a decreasing stack of indices
    for (int i = 0; i < numsSize; i++) {
        if (top == 0 || nums[i] < nums[stack[top-1]]) {
            stack[top++] = i;
        }
    }
    
    int maxWidth = 0;
    
    // Iterate from right to left to find the maximum width
    for (int i = numsSize - 1; i >= 0; i--) {
        while (top > 0 && nums[i] >= nums[stack[top-1]]) {
            maxWidth = MAX(maxWidth, i - stack[top-1]);
            top--;
        }
    }
    
    free(stack);
    return maxWidth;
}