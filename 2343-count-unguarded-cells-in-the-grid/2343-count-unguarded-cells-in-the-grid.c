int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    int grid[m][n];
    
    // Initialize the grid with:
    // 0 = unoccupied cell
    // 1 = wall
    // 2 = guard
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = 0;  // Start with unoccupied cells
        }
    }
    
    // Mark the walls in the grid
    for (int i = 0; i < wallsSize; ++i) {
        int r = walls[i][0], c = walls[i][1];
        grid[r][c] = 1;  // Mark wall
    }
    
    // Mark the guards in the grid
    for (int i = 0; i < guardsSize; ++i) {
        int r = guards[i][0], c = guards[i][1];
        grid[r][c] = 2;  // Mark guard
    }
    
    // Direction vectors for north, east, south, and west
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    // Mark the cells that are guarded
    for (int i = 0; i < guardsSize; ++i) {
        int r = guards[i][0], c = guards[i][1];
        
        // For each direction, propagate the guard's sight
        for (int d = 0; d < 4; ++d) {
            int nr = r, nc = c;
            
            // Move in the current direction until we hit a wall or grid boundary
            while (true) {
                nr += directions[d][0];
                nc += directions[d][1];
                
                // Check for boundary or wall or guard
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == 1 || grid[nr][nc] == 2) {
                    break;
                }
                
                // Mark the cell as guarded
                grid[nr][nc] = 3;  // Mark as guarded
            }
        }
    }
    
    // Now count the unguarded, unoccupied cells
    int unguardedCount = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Cell is unoccupied (0) and not guarded (not 3)
            if (grid[i][j] == 0) {
                unguardedCount++;
            }
        }
    }
    
    return unguardedCount;
}