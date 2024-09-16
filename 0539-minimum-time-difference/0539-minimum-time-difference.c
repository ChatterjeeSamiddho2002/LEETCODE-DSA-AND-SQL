int timeToMinutes(char* time) {
    int hours = (time[0] - '0') * 10 + (time[1] - '0');
    int minutes = (time[3] - '0') * 10 + (time[4] - '0');
    return hours * 60 + minutes;
}

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int findMinDifference(char** timePoints, int timePointsSize) {
      if (timePointsSize > 1440) {
        // There are only 1440 minutes in a day, so if there are more time points than that,
        // at least two of them must be the same, meaning the minimum difference is 0.
        return 0;
    }

    // Array to store time points in minutes
    int times[timePointsSize];
    
    // Convert each time point to minutes and store it
    for (int i = 0; i < timePointsSize; i++) {
        times[i] = timeToMinutes(timePoints[i]);
    }
    
    // Sort the time points in ascending order of minutes
    qsort(times, timePointsSize, sizeof(int), compare);
    
    // Initialize the minimum difference to a large value
    int minDiff = 1440;
    
    // Compute the difference between consecutive time points
    for (int i = 1; i < timePointsSize; i++) {
        int diff = times[i] - times[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    
    // Account for the circular nature of the clock
    // Compare the first and last time points across midnight
    int circularDiff = 1440 - (times[timePointsSize - 1] - times[0]);
    if (circularDiff < minDiff) {
        minDiff = circularDiff;
    }
    
    return minDiff;
}

