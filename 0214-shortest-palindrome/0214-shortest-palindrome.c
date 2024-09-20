void computeLPSArray(char *str, int *lps, int len) {
    int length = 0; // length of the previous longest prefix suffix
    lps[0] = 0;     // lps[0] is always 0

    int i = 1;
    while (i < len) {
        if (str[i] == str[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
char* shortestPalindrome(char* s) {
    int len = strlen(s);
    if (len <= 1) return s;

    // Create a new string for LPS calculation
    char *newStr = (char *)malloc((2 * len + 2) * sizeof(char));
    if (!newStr) return NULL;
    
    strcpy(newStr, s);
    newStr[len] = '#';
    
    for (int i = 0; i < len; i++) {
        newStr[len + 1 + i] = s[len - 1 - i];
    }
    newStr[2 * len + 1] = '\0';

    // Create LPS array
    int *lps = (int *)malloc((2 * len + 2) * sizeof(int));
    if (!lps) {
        free(newStr);
        return NULL;
    }
    computeLPSArray(newStr, lps, 2 * len + 1);

    // Find the length of the longest palindromic prefix
    int longestPalinPrefixLen = lps[2 * len];

    // If the entire string is a palindrome, return it as is
    if (longestPalinPrefixLen == len) {
        free(newStr);
        free(lps);
        return strdup(s);
    }

    // Create the shortest palindrome
    int resultLen = 2 * len - longestPalinPrefixLen;
    char *result = (char *)malloc((resultLen + 1) * sizeof(char));
    if (!result) {
        free(newStr);
        free(lps);
        return NULL;
    }

    // Add characters to the front from the reversed string
    int index = 0;
    for (int i = len - 1; i >= longestPalinPrefixLen; i--) {
        result[index++] = s[i];
    }

    // Append the original string
    strcpy(result + index, s);
    result[resultLen] = '\0';

    // Free allocated memory
    free(newStr);
    free(lps);

    return result;
}