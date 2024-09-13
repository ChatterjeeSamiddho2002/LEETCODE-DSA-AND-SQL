/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize; // The number of results is the same as the number of queries.
    int* result = malloc(queriesSize * sizeof(int)); // Allocate memory for the result array.
    
    // Create the prefix XOR array.
    int* prefixXOR = malloc(arrSize * sizeof(int));
    prefixXOR[0] = arr[0];
    for (int i = 1; i < arrSize; i++) {
        prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
    }
    
    // Process each query.
    for (int i = 0; i < queriesSize; i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        
        if (left == 0) {
            // If the query starts from the beginning of the array.
            result[i] = prefixXOR[right];
        } else {
            // Otherwise, use the prefix XOR array to find the result.
            result[i] = prefixXOR[right] ^ prefixXOR[left - 1];
        }
    }
    
    free(prefixXOR); // Free the prefix XOR array.
    return result;
}
