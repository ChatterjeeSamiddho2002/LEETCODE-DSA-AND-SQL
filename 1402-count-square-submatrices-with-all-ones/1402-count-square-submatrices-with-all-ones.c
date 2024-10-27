int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
   if (matrixSize == 0 || *matrixColSize == 0) return 0;

    int m = matrixSize;
    int n = *matrixColSize;
    int count = 0;

    // Create a dp array to store the size of the largest square submatrix
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    // Fill in the dp array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;  // First row or first column
                } else {
                    dp[i][j] = fmin(dp[i-1][j], fmin(dp[i][j-1], dp[i-1][j-1])) + 1;
                }
                count += dp[i][j];  // Add the number of squares ending at (i, j)
            } else {
                dp[i][j] = 0;  // No square ending here if the matrix value is 0
            }
        }
    }

    // Free allocated memory for dp
    for (int i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);

    return count; 
}