int countPalindromicSubsequence(char* s) {
    int n = strlen(s);
    int count = 0;
    
    // Iterate over each character 'a' to 'z'
    for (char x = 'a'; x <= 'z'; x++) {
        int first = -1, last = -1;
        
        // Find the first and last occurrence of character x
        for (int i = 0; i < n; i++) {
            if (s[i] == x) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        
        // If there's a valid range (at least one character between first and last)
        if (first != -1 && last - first > 1) {
            bool seen[26] = {false};  // Track unique characters between first and last
            
            // Count unique characters between first and last occurrence of x
            for (int i = first + 1; i < last; i++) {
                seen[s[i] - 'a'] = true;
            }
            
            // Count the number of unique characters
            for (int i = 0; i < 26; i++) {
                if (seen[i]) {
                    count++;
                }
            }
        }
    }
    
    return count;
}