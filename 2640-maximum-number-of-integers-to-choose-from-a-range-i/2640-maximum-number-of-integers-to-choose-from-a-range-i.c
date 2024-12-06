int maxCount(int* banned, int bannedSize, int n, int maxSum) {
      // Use a hash set approach for faster banned number lookup
    bool* bannedSet = calloc(n + 1, sizeof(bool));
    
    // Mark banned numbers efficiently
    for (int i = 0; i < bannedSize; i++) {
        if (banned[i] <= n) {
            bannedSet[banned[i]] = true;
        }
    }

    int count = 0;
    int currentSum = 0;

    // Iterate through numbers from 1 to n
    for (int num = 1; num <= n; num++) {
        // Check if number is not banned and can be added without exceeding maxSum
        if (!bannedSet[num] && currentSum + num <= maxSum) {
            currentSum += num;
            count++;
        }
    }

    // Free dynamically allocated memory
    free(bannedSet);

    return count;
}