int takeCharacters(char* s, int k) {
     int cnt[3] = {};  // Count of 'a', 'b', and 'c'
    int n = strlen(s);  // Length of the string (C-style)
    int res = -1;  // Initialize result to -1 (impossible case)
    
    // Count the occurrences of 'a', 'b', 'c' in the entire string
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    
    // If any character has fewer than 'k' occurrences, return -1
    if (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
        return -1;
    }
    
    // Sliding window approach
    for (int i = 0, j = 0; i < n; ++i) {
        --cnt[s[i] - 'a'];  // Decrease the count of the character at the left end
        
        // If any character is below k, move the right pointer `j`
        while (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
            ++cnt[s[j] - 'a'];
            ++j;  // Shrink the window from the left
        }
        
        // Track the maximum window size where the condition is satisfied
        res = res > (i - j + 1) ? res : (i - j + 1);
    }
    
    // The result is the total length minus the longest valid window
    return n - res;
}