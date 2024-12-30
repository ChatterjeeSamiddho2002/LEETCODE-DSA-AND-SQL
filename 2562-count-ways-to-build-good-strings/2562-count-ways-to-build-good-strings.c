int countGoodStrings(int low, int high, int zero, int one) {
     const int MOD = 1000000007;
    int ways[high + 1];
    
    // Initialize the ways array
    for (int i = 0; i <= high; ++i) {
        ways[i] = 0;
    }
    ways[0] = 1; // Base case
    
    for (int length = 0; length <= high; ++length) {
        if (ways[length] == 0) continue;
        if (length + zero <= high) {
            ways[length + zero] = (ways[length + zero] + ways[length]) % MOD;
        }
        if (length + one <= high) {
            ways[length + one] = (ways[length + one] + ways[length]) % MOD;
        }
    }
    
    int count = 0;
    for (int i = low; i <= high; ++i) {
        count = (count + ways[i]) % MOD;
    }
    
    return count;
}