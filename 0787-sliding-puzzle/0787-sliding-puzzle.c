typedef struct {
    char state[7]; // Flattened representation of the 2x3 board
    int moves;     // Number of moves taken to reach this state
} Node;
int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
   // Target solved state
    const char target[] = "123450";

    // Convert the input board into a string representation
    char start[7] = {0};
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            start[i * boardColSize[i] + j] = board[i][j] + '0';
        }
    }

    // If the board is already solved
    if (strcmp(start, target) == 0) return 0;

    // Predefined neighbors based on the position of '0'
    int swaps[6][4] = {
        {1, 3, -1, -1}, {0, 2, 4, -1}, {1, 5, -1, -1},
        {0, 4, -1, -1}, {1, 3, 5, -1}, {2, 4, -1, -1}
    };

    // Queue for BFS
    Node queue[720];
    int front = 0, rear = 0;

    // Visited set
    char visited[720][7];
    int visitedCount = 0;

    // Initialize BFS
    queue[rear++] = (Node){.state = {0}, .moves = 0};
    strcpy(queue[rear - 1].state, start);

    while (front < rear) {
        // Dequeue a node
        Node current = queue[front++];
        strcpy(visited[visitedCount++], current.state);

        // Find the position of '0'
        int zeroPos = strchr(current.state, '0') - current.state;

        // Try all possible swaps
        for (int i = 0; swaps[zeroPos][i] != -1; i++) {
            int newZeroPos = swaps[zeroPos][i];

            // Create a new state by swapping
            char newState[7];
            strcpy(newState, current.state);
            newState[zeroPos] = newState[newZeroPos];
            newState[newZeroPos] = '0';

            // If solved, return the number of moves
            if (strcmp(newState, target) == 0) {
                return current.moves + 1;
            }

            // Check if the new state is already visited
            int isVisited = 0;
            for (int j = 0; j < visitedCount; j++) {
                if (strcmp(newState, visited[j]) == 0) {
                    isVisited = 1;
                    break;
                }
            }
            if (!isVisited) {
                queue[rear++] = (Node){.state = {0}, .moves = current.moves + 1};
                strcpy(queue[rear - 1].state, newState);
            }
        }
    }

    // If no solution is found
    return -1;  
}