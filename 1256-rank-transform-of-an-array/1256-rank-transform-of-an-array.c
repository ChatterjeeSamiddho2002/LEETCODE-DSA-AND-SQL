/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct {
    int value;
    int index;
} ValueIndex;

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return ((ValueIndex*)a)->value - ((ValueIndex*)b)->value;
}
int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
     *returnSize = arrSize;
    if (arrSize == 0) return NULL;

    // Create an array of ValueIndex structs
    ValueIndex* valueIndices = malloc(arrSize * sizeof(ValueIndex));
    for (int i = 0; i < arrSize; i++) {
        valueIndices[i].value = arr[i];
        valueIndices[i].index = i;
    }

    // Sort the array based on values
    qsort(valueIndices, arrSize, sizeof(ValueIndex), compare);

    // Create the result array
    int* result = malloc(arrSize * sizeof(int));

    // Assign ranks
    int rank = 1;
    result[valueIndices[0].index] = rank;

    for (int i = 1; i < arrSize; i++) {
        if (valueIndices[i].value != valueIndices[i-1].value) {
            rank++;
        }
        result[valueIndices[i].index] = rank;
    }

    // Free allocated memory
    free(valueIndices);

    return result;
}