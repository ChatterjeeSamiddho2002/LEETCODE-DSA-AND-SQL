typedef struct {
    int time;
    int isStart;
} Event;

int compareEvents(const void* a, const void* b) {
    Event* eventA = (Event*)a;
    Event* eventB = (Event*)b;
    if (eventA->time != eventB->time)
        return eventA->time - eventB->time;
    // If times are equal, end events come before start events
    return eventB->isStart - eventA->isStart;
}

int minGroups(int** intervals, int intervalsSize, int* intervalsColSize) {
    // Create an array of events
    Event* events = (Event*)malloc(2 * intervalsSize * sizeof(Event));
    if (events == NULL) return -1;  // Memory allocation failed

    // Populate the events array
    for (int i = 0; i < intervalsSize; i++) {
        events[2*i] = (Event){intervals[i][0], 1};  // Start event
        events[2*i+1] = (Event){intervals[i][1], 0};  // End event
    }

    // Sort the events
    qsort(events, 2 * intervalsSize, sizeof(Event), compareEvents);

    int maxGroups = 0;
    int currentGroups = 0;

    // Process events
    for (int i = 0; i < 2 * intervalsSize; i++) {
        if (events[i].isStart) {
            currentGroups++;
            if (currentGroups > maxGroups) {
                maxGroups = currentGroups;
            }
        } else {
            currentGroups--;
        }
    }

    free(events);
    return maxGroups;
}