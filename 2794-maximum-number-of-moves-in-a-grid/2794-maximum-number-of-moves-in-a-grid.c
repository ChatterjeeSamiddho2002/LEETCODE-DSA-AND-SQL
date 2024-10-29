int dfs(int** grid, int rows, int cols, int r, int c, int** memo) {
    // If we've already computed the result for this cell, return it
    if (memo[r][c] != -1) {
        return memo[r][c];
    }

    int maxMoves = 0;
    
    // Possible moves: (row - 1, col + 1), (row, col + 1), (row + 1, col + 1)
    int directions[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
    
    for (int i = 0; i < 3; i++) {
        int newRow = r + directions[i][0];
        int newCol = c + directions[i][1];
        
        // Check boundaries and value condition
        if (newRow >= 0 && newRow < rows && newCol < cols && grid[newRow][newCol] > grid[r][c]) {
            maxMoves = fmax(maxMoves, 1 + dfs(grid, rows, cols, newRow, newCol, memo));
        }
    }

    // Store the result in memoization array
    memo[r][c] = maxMoves;
    return maxMoves;
}
int maxMoves(int** grid, int gridSize, int* gridColSize) {
  int rows = gridSize;
    int cols = *gridColSize;
    int maxOverallMoves = 0;

    // Memoization array
    int** memo = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        memo[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            memo[i][j] = -1; // Initialize memoization array with -1
        }
    }

    // Start DFS from every cell in the first column
    for (int i = 0; i < rows; i++) {
        maxOverallMoves = fmax(maxOverallMoves, dfs(grid, rows, cols, i, 0, memo));
    }

    // Free memoization array
    for (int i = 0; i < rows; i++) {
        free(memo[i]);
    }
    free(memo);

    return maxOverallMoves;   
}