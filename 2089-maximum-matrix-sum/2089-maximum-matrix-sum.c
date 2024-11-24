long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long totalSum = 0;
    long long minAbsValue = LONG_MAX;
    int negativeCount = 0;
    
    // Traverse the matrix to calculate the sum of absolute values
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            int val = matrix[i][j];
            totalSum += abs(val); // Add the absolute value of each element
            if (val < 0) {
                negativeCount++; // Count the negative elements
            }
            minAbsValue = fmin(minAbsValue, abs(val)); // Track the minimum absolute value
        }
    }
    
    // If the number of negative elements is odd, we have to flip one of the negatives
    if (negativeCount % 2 != 0) {
        totalSum -= 2 * minAbsValue; // Subtract the smallest absolute value twice (to make it positive)
    }
    
    return totalSum;
}