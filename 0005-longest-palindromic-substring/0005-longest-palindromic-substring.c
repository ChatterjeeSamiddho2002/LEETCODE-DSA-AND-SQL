char* longestPalindrome(char* s) {
        int n = strlen(s);
    if (n == 0) return "";
    
    int start = 0, maxLength = 1;

    // Helper function to expand around the center
    void expandAroundCenter(char* s, int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        int length = right - left - 1; // Length of the palindrome
        if (length > maxLength) {
            start = left + 1;
            maxLength = length;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        // Odd-length palindromes
        expandAroundCenter(s, i, i);
        // Even-length palindromes
        expandAroundCenter(s, i, i + 1);
    }

    // Allocate memory for the result substring
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\0'; // Null-terminate the string
    return result;
}
