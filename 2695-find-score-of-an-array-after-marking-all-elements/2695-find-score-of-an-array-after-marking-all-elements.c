int compare(const void *a, const void *b) {
    int val_a = ((int*)a)[0];
    int val_b = ((int*)b)[0];
    if (val_a == val_b) {
        return ((int*)a)[1] - ((int*)b)[1];
    }
    return val_a - val_b;
}
long long findScore(int* nums, int numsSize) {
    // Create an array of pairs (value, index) for sorting.
    int arr[numsSize][2];  // arr[i][0] is value, arr[i][1] is the original index
    for (int i = 0; i < numsSize; i++) {
        arr[i][0] = nums[i];
        arr[i][1] = i;
    }

    // Sort the array by value and by index in case of ties.
    qsort(arr, numsSize, sizeof(arr[0]), compare);

    // Boolean array to keep track of marked elements.
    bool marked[numsSize];
    for (int i = 0; i < numsSize; i++) {
        marked[i] = false;
    }

    long long score = 0;

    // Process each element in sorted order
    for (int i = 0; i < numsSize; i++) {
        int idx = arr[i][1]; // Original index of the current smallest unmarked element

        // If the element is already marked, skip it
        if (marked[idx]) continue;

        // Add its value to the score
        score += nums[idx];
        
        // Mark the element and its adjacent elements
        marked[idx] = true;
        
        if (idx > 0) marked[idx - 1] = true;  // Mark left neighbor
        if (idx < numsSize - 1) marked[idx + 1] = true;  // Mark right neighbor
    }

    return score;
}