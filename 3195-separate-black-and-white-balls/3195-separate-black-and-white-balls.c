long long minimumSteps(char* s) {
long long n = strlen(s);
    long long black_count = 0;
    long long swaps = 0;
    
    // Count total black balls and calculate swaps
    for (long long i = 0; i < n; i++) {
        if (s[i] == '1') {
            black_count++;
        } else {
            swaps += black_count;
        }
    }
    
    return swaps;    
}