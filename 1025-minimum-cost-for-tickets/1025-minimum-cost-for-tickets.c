#define MAX_DAYS 366 
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
   int dp[MAX_DAYS] = {0};
    int travel[MAX_DAYS] = {0}; // Track travel days

    // Mark travel days
    for (int i = 0; i < daysSize; i++) {
        travel[days[i]] = 1;
    }

    // Fill DP table
    for (int i = 1; i < MAX_DAYS; i++) {
        if (!travel[i]) {
            dp[i] = dp[i - 1];  // If no travel, cost stays the same
        } else {
            dp[i] = MIN(dp[i - 1] + costs[0],  // 1-day pass
                        MIN(dp[MAX(0, i - 7)] + costs[1],  // 7-day pass
                            dp[MAX(0, i - 30)] + costs[2])); // 30-day pass
        }
    }

    return dp[365]; 
}