int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    // Prefix sums
    int rowSum[m][n + 1];
    int colSum[m + 1][n];
    int diag1[m + 1][n + 1]; // top-left to bottom-right
    int diag2[m + 1][n + 1]; // top-right to bottom-left

    // Initialize prefix sums
    for (int i = 0; i < m; i++) {
        rowSum[i][0] = 0;
        for (int j = 0; j < n; j++)
            rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
    }

    for (int j = 0; j < n; j++) {
        colSum[0][j] = 0;
        for (int i = 0; i < m; i++)
            colSum[i + 1][j] = colSum[i][j] + grid[i][j];
    }

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            diag1[i][j] = diag2[i][j] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
            diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
        }
    }

    int maxSize = (m < n) ? m : n;

    // Try larger sizes first
    for (int k = maxSize; k >= 2; k--) {
        for (int r = 0; r + k <= m; r++) {
            for (int c = 0; c + k <= n; c++) {

                int target = rowSum[r][c + k] - rowSum[r][c];
                int valid = 1;

                // Check rows
                for (int i = r; i < r + k; i++) {
                    if (rowSum[i][c + k] - rowSum[i][c] != target) {
                        valid = 0;
                        break;
                    }
                }

                // Check columns
                for (int j = c; j < c + k && valid; j++) {
                    if (colSum[r + k][j] - colSum[r][j] != target) {
                        valid = 0;
                        break;
                    }
                }

                // Check diagonals
                int d1 = diag1[r + k][c + k] - diag1[r][c];
                int d2 = diag2[r + k][c] - diag2[r][c + k];

                if (valid && d1 == target && d2 == target)
                    return k;
            }
        }
    }

    return 1; // At least 1x1 is always magic
}
