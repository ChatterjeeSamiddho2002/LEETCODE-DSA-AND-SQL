char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
        int n = strlen(s);
    int* shift = (int*)calloc(n + 1, sizeof(int));  // Difference array
    
    // Apply shifts using difference array
    for (int i = 0; i < shiftsSize; i++) {
        int start = shifts[i][0];
        int end = shifts[i][1];
        int direction = shifts[i][2];
        
        // Increment shift for forward, decrement for backward
        if (direction == 1) {
            shift[start] += 1;
            shift[end + 1] -= 1;
        } else {
            shift[start] -= 1;
            shift[end + 1] += 1;
        }
    }
    
    // Calculate prefix sum to get final shifts
    int cumulativeShift = 0;
    for (int i = 0; i < n; i++) {
        cumulativeShift += shift[i];
        int newChar = ((s[i] - 'a' + cumulativeShift) % 26 + 26) % 26;  // Handle wrap-around
        s[i] = 'a' + newChar;
    }
    
    // Free allocated memory
    free(shift);
    
    return s;

}