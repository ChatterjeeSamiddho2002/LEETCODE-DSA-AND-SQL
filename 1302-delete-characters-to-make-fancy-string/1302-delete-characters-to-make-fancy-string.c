char* makeFancyString(char* s) {
  int n = strlen(s);
    // Allocate memory for the maximum possible size (if no characters are removed)
    char* result = (char*)malloc(n + 1);
    int j = 0; // Index for the result string

    for (int i = 0; i < n; i++) {
        // Check the last two characters in the result
        if (j >= 2 && result[j - 1] == s[i] && result[j - 2] == s[i]) {
            continue; // Skip adding this character
        }
        result[j++] = s[i]; // Add character to result
    }

    result[j] = '\0'; // Null-terminate the result string
    return result;   
}