char* addSpaces(char* s, int* spaces, int spacesSize) {
    // First, create a set of space indices
    int *spaceSet = (int*)malloc(spacesSize * sizeof(int));
    for (int i = 0; i < spacesSize; i++) {
        spaceSet[i] = spaces[i];
    }

    // Determine the length of the original string s
    int len = strlen(s);
    
    // Create a dynamic array for the result
    char* result = (char*)malloc((len + spacesSize + 1) * sizeof(char));  // space for spaces and null-terminator
    int resultIndex = 0;
    
    // Track the next space index
    int spaceIndex = 0;
    
    // Loop through the string
    for (int i = 0; i < len; i++) {
        // If the current index matches one of the indices in spaces, add a space
        if (spaceIndex < spacesSize && spaces[spaceIndex] == i) {
            result[resultIndex++] = ' ';  // Add space
            spaceIndex++;  // Move to the next space index
        }
        
        // Add the current character from the original string
        result[resultIndex++] = s[i];
    }
    
    // Null-terminate the result string
    result[resultIndex] = '\0';
    
    // Free spaceSet as it's no longer needed
    free(spaceSet);
    
    return result;
}