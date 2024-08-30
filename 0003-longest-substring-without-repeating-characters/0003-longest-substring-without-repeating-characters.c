int lengthOfLongestSubstring(char* s) {
 int n = strlen(s);
    int charIndex[128] = {0};  // Assuming ASCII characters
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        if (charIndex[s[end]] > start) {
            start = charIndex[s[end]];
        }
        charIndex[s[end]] = end + 1;
        maxLength = fmax(maxLength, end - start + 1);
    }

    return maxLength;
}