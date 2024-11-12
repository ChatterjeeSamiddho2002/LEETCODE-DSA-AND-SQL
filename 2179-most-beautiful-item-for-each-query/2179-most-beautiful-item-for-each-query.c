/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int compareItems(const void* a, const void* b) {
    int* itemA = *(int**)a;
    int* itemB = *(int**)b;
    
    // Sort primarily by price, secondarily by beauty in descending order
    if (itemA[0] == itemB[0]) {
        return itemB[1] - itemA[1];  // Reverse order for beauty
    }
    return itemA[0] - itemB[0];  // Ascending order for price
}
int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize) {
      // Sort the items based on price first and beauty second
    qsort(items, itemsSize, sizeof(int*), compareItems);
    
    // Precompute the maximum beauty for each price.
    int* prices = (int*)malloc(itemsSize * sizeof(int));
    int* maxBeauty = (int*)malloc(itemsSize * sizeof(int));
    
    // Initialize first price and beauty
    prices[0] = items[0][0];
    maxBeauty[0] = items[0][1];
    
    for (int i = 1; i < itemsSize; i++) {
        prices[i] = items[i][0];
        maxBeauty[i] = (items[i][1] > maxBeauty[i - 1]) ? items[i][1] : maxBeauty[i - 1];
    }
    
    // Prepare the result array for queries
    int* result = (int*)malloc(queriesSize * sizeof(int));
    
    // Answer each query using binary search
    for (int i = 0; i < queriesSize; i++) {
        int left = 0, right = itemsSize - 1;
        int bestBeauty = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (prices[mid] <= queries[i]) {
                bestBeauty = maxBeauty[mid];
                left = mid + 1;  // Search for a higher price
            } else {
                right = mid - 1; // Search for a lower price
            }
        }
        
        result[i] = bestBeauty;
    }
    
    // Set the return size
    *returnSize = queriesSize;
    
    // Return the result array
    return result;
}