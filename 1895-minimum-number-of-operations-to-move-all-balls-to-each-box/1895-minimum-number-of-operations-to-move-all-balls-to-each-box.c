/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);
    int* answer = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    
    int operations = 0;  // Total operations to bring balls to current box
    int count = 0;       // Number of balls seen so far
    
    // First pass (left to right)
    for (int i = 0; i < n; i++) {
        answer[i] = operations;
        count += (boxes[i] == '1');  // Count balls
        operations += count;          // Add operations for each ball
    }
    
    // Reset for the second pass
    operations = 0;
    count = 0;
    
    // Second pass (right to left)
    for (int i = n - 1; i >= 0; i--) {
        answer[i] += operations;       // Accumulate operations from the right
        count += (boxes[i] == '1');    // Count balls from the right
        operations += count;           // Add operations for each ball
    }
    
    return answer;
}