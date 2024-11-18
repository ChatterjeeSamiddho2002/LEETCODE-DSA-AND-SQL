/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
     int* decrypted = (int*)malloc(codeSize * sizeof(int));
    *returnSize = codeSize;  // The size of the array is always the same as codeSize
    
    // If k == 0, we just return an array of zeros
    if (k == 0) {
        for (int i = 0; i < codeSize; i++) {
            decrypted[i] = 0;
        }
        return decrypted;
    }
    
    // Loop through each index in the array and calculate the new values
    for (int i = 0; i < codeSize; i++) {
        int sum = 0;
        
        // If k > 0, sum the next k elements
        if (k > 0) {
            for (int j = 1; j <= k; j++) {
                sum += code[(i + j) % codeSize];  // Use modulo for circular indexing
            }
        }
        // If k < 0, sum the previous |k| elements
        else if (k < 0) {
            for (int j = 1; j <= -k; j++) {
                sum += code[(i - j + codeSize) % codeSize];  // Use modulo for circular indexing
            }
        }
        
        decrypted[i] = sum;
    }
    
    return decrypted;
}