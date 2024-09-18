int compare(const void* a, const void* b) {
    char* order1 = (char*)malloc(strlen(*(char**)a) + strlen(*(char**)b) + 1);
    char* order2 = (char*)malloc(strlen(*(char**)a) + strlen(*(char**)b) + 1);
    
    // Concatenate in both orders
    strcpy(order1, *(char**)a);
    strcat(order1, *(char**)b);
    
    strcpy(order2, *(char**)b);
    strcat(order2, *(char**)a);
    
    // Compare the two orders
    int result = strcmp(order2, order1); // reverse order for descending sort
    
    free(order1);
    free(order2);
    
    return result;
}
char* largestNumber(int* nums, int numsSize) {
    // Array to store the string representation of numbers
    char** strNums = (char**)malloc(numsSize * sizeof(char*));
    
    // Convert each number to a string
    for (int i = 0; i < numsSize; i++) {
        strNums[i] = (char*)malloc(12 * sizeof(char)); // Max size for int
        sprintf(strNums[i], "%d", nums[i]);
    }
    
    // Sort the string representations using the custom comparator
    qsort(strNums, numsSize, sizeof(char*), compare);
    
    // Handle edge case where the largest number is '0'
    if (strcmp(strNums[0], "0") == 0) {
        free(strNums);
        return "0";
    }
    
    // Concatenate the sorted string numbers
    int totalLength = 0;
    for (int i = 0; i < numsSize; i++) {
        totalLength += strlen(strNums[i]);
    }
    
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    result[0] = '\0';  // Initialize result string
    
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strNums[i]);
        free(strNums[i]);  // Free individual string after use
    }
    
    free(strNums);  // Free the array of string pointers
    
    return result;
}