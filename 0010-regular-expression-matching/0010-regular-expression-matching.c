bool charMatch(char s, char p) {
    return (p == '.' || s == p);
}

bool isMatch(char* s, char* p) {
    int lenS = strlen(s);
    int lenP = strlen(p);
    
    // dp[i][j] will be true if s[0...i-1] matches p[0...j-1]
    bool dp[lenS + 1][lenP + 1];
    
    // Initialize the dp array
    memset(dp, false, sizeof(dp));
    
    // Empty string matches with empty pattern
    dp[0][0] = true;
    
    // Handle patterns like a*, a*b*, etc., that could match an empty string
    for (int j = 1; j <= lenP; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    
    // Fill the dp table
    for (int i = 1; i <= lenS; i++) {
        for (int j = 1; j <= lenP; j++) {
            if (p[j - 1] == '*') {
                // '*' can match zero or more of the preceding element
                dp[i][j] = dp[i][j - 2]; // Case where '*' matches zero occurrences
                
                // Case where '*' matches one or more occurrences
                if (charMatch(s[i - 1], p[j - 2])) {
                    dp[i][j] |= dp[i - 1][j];
                }
            } else {
                // Normal case where either characters match or pattern has '.'
                if (charMatch(s[i - 1], p[j - 1])) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
    }
    
    // The result is whether the entire string matches the entire pattern
    return dp[lenS][lenP];
}