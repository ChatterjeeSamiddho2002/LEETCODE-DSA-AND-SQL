typedef struct {
    int x;
    int y;
} Point;

// Function to compare two points for qsort
int comparePoints(const void* a, const void* b) {
    Point* pointA = (Point*)a;
    Point* pointB = (Point*)b;

    if (pointA->x == pointB->x) {
        return pointA->y - pointB->y;
    }
    return pointA->x - pointB->x;
}

// Binary search to check if the next position is an obstacle
bool isObstacle(Point* obstacles, int obstaclesSize, int x, int y) {
    Point key = {x, y};
    return bsearch(&key, obstacles, obstaclesSize, sizeof(Point), comparePoints) != NULL;
}
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
     int directionX[4] = {0, 1, 0, -1};  // N, E, S, W X-deltas
    int directionY[4] = {1, 0, -1, 0};  // N, E, S, W Y-deltas
    int direction = 0;  // Initially facing North
    int x = 0, y = 0;   // Start at the origin
    int maxDist = 0;

    // Create and sort obstacles array for binary search
    Point* obstacleSet = (Point*)malloc(obstaclesSize * sizeof(Point));
    for (int i = 0; i < obstaclesSize; i++) {
        obstacleSet[i].x = obstacles[i][0];
        obstacleSet[i].y = obstacles[i][1];
    }
    qsort(obstacleSet, obstaclesSize, sizeof(Point), comparePoints);

    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] == -2) {  // Turn left
            direction = (direction + 3) % 4;
        } else if (commands[i] == -1) {  // Turn right
            direction = (direction + 1) % 4;
        } else {  // Move forward
            int steps = commands[i];
            while (steps-- > 0) {
                int newX = x + directionX[direction];
                int newY = y + directionY[direction];

                // Check for obstacles
                if (isObstacle(obstacleSet, obstaclesSize, newX, newY)) {
                    break;  // Stop if hitting an obstacle
                }

                // Move the robot
                x = newX;
                y = newY;

                // Calculate and update the max distance squared
                int distSquared = x * x + y * y;
                if (distSquared > maxDist) {
                    maxDist = distSquared;
                }
            }
        }
    }

    // Clean up
    free(obstacleSet);
    
    return maxDist;
}

