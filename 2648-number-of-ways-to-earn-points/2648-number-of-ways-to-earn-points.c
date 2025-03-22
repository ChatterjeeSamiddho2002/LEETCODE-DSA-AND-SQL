#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int waysToReachTarget(int target, int** types, int typesSize, int* typesColSize) {
    int* dp = (int*)calloc(target + 1, sizeof(int));
    dp[0] = 1; // There is one way to make zero points

    for (int i = 0; i < typesSize; i++) {
        int count = types[i][0]; // Number of questions of this type
        int marks = types[i][1]; // Marks per question

        // Process from high to low to prevent using the same question multiple times
        for (int j = target; j >= 0; j--) {
            // Try using 1 to count questions of this type
            for (int k = 1; k <= count && j - k * marks >= 0; k++) {
                dp[j] = (dp[j] + dp[j - k * marks]) % MOD;
            }
        }
    }

    int result = dp[target];
    free(dp);
    return result;
}
