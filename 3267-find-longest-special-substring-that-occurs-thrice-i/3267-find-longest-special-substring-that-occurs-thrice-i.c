int maximumLength(char* s) {
    int n = strlen(s);
    if (n < 3) return -1; // If the string is too short, no special substring can occur 3 times.

    // This will store the count of each special substring
    int counts[26][n+1]; // counts[i][j] will store how many times the substring of 'i' characters 'a' occurs in the string
    
    memset(counts, 0, sizeof(counts));
    
    // Iterate over all possible special substrings of length 1 to n
    for (int start = 0; start < n; start++) {
        char ch = s[start];
        for (int len = 1; start + len <= n; len++) {
            if (s[start + len - 1] == ch) {
                counts[ch - 'a'][len]++;  // count the current substring by the substring length we currently use
            } else {
                break;
            }
        }
    }

    int max_len = -1;
    for (int len = 1; len < n + 1; len++) {
        for (int i = 0; i < 26; i++) {
            // Look for max len with value atleast 3
            if (counts[i][len] >= 3) {
                max_len = len;
            }
        }
    }

    return max_len; 
}