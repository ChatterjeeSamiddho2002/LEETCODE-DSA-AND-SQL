/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lexicalOrder(int n, int* returnSize) {
        int* result = (int*)malloc(n * sizeof(int));  // Array to store result
    int curr = 1;  // Start with 1 in lexicographical order
    
    for (int i = 0; i < n; i++) {
        result[i] = curr;
        
        // Try to move to the next lexicographical number
        if (curr * 10 <= n) {
            curr *= 10;  // Go deeper in lexicographical order
        } else {
            // If we can't multiply by 10, try incrementing the current number
            if (curr >= n) {
                curr /= 10;  // Move up a level
            }
            curr++;  // Go to the next number
            // If we hit a number ending in 0, keep moving up (backtrack)
            while (curr % 10 == 0) {
                curr /= 10;
            }
        }
    }
    
    *returnSize = n;  // Set the return size
    return result;
}