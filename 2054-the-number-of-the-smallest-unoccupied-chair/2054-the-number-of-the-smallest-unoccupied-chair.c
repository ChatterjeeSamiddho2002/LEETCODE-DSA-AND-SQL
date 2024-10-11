typedef struct {
    int arrival;
    int leaving;
    int index;
} Friend;

// Comparator function for sorting friends by arrival time
int compare(const void *a, const void *b) {
    return ((Friend *)a)->arrival - ((Friend *)b)->arrival;
}

int smallestChair(int** times, int timesSize, int* timesColSize, int targetFriend) {
     Friend *friends = malloc(timesSize * sizeof(Friend));
    
    // Populate the friends array
    for (int i = 0; i < timesSize; i++) {
        friends[i].arrival = times[i][0];
        friends[i].leaving = times[i][1];
        friends[i].index = i;
    }

    // Sort friends by arrival time
    qsort(friends, timesSize, sizeof(Friend), compare);

    // Array to track the time when chairs become free
    int *chairs = calloc(timesSize, sizeof(int));
    int chairCount = 0;

    for (int i = 0; i < timesSize; i++) {
        // Free up chairs that have become available before the current friend's arrival
        for (int j = 0; j < chairCount; j++) {
            if (chairs[j] <= friends[i].arrival) {
                chairs[j] = -1; // Mark the chair as free
            }
        }

        // Find the first available chair
        int assignedChair = -1;
        for (int j = 0; j < chairCount; j++) {
            if (chairs[j] == -1) {
                assignedChair = j; // Found a free chair
                break;
            }
        }
        
        // If no free chair found, assign a new chair
        if (assignedChair == -1) {
            assignedChair = chairCount++;
        }

        // Mark the chair with the time it will become free
        chairs[assignedChair] = friends[i].leaving;

        // If this is the target friend, return the chair number
        if (friends[i].index == targetFriend) {
            free(friends);
            free(chairs);
            return assignedChair;
        }
    }

    free(friends);
    free(chairs);
    return -1; // In case of an error
}