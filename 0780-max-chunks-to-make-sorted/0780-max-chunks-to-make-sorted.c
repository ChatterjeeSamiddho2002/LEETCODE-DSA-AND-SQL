int maxChunksToSorted(int* arr, int arrSize) {
    int maxValue = 0;
    int chunks = 0;

    for (int i = 0; i < arrSize; i++) {
        // Update the maximum value encountered so far
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }

        // If the maximum value equals the current index, we can form a chunk
        if (maxValue == i) {
            chunks++;
        }
    }

    return chunks;
}