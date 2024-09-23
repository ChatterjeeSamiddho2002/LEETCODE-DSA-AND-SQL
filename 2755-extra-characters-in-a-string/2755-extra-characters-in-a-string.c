#define MAX_LEN 1000
bool isWordInDictionary(char* s, int start, int end, char** dictionary, int dictSize) {
    char temp[MAX_LEN];
    int length = end - start + 1;
    strncpy(temp, s + start, length);
    temp[length] = '\0'; // Null-terminate the substring
    
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(temp, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}
int minExtraChar(char * s, char ** dictionary, int dictionarySize){
 int sLength = strlen(s);
    int dp[MAX_LEN + 1]; // DP array to store results
    
    // Initialize DP array
    for (int i = 0; i <= sLength; i++) {
        dp[i] = sLength - i; // Worst case: all characters are extra
    }
    
    // Fill the DP array
    for (int i = sLength - 1; i >= 0; i--) {
        // Assume this character is extra
        dp[i] = dp[i + 1] + 1;
        
        // Try all possible substrings starting from index i
        for (int j = i; j < sLength; j++) {
            if (isWordInDictionary(s, i, j, dictionary, dictionarySize)) {
                dp[i] = (dp[j + 1] < dp[i]) ? dp[j + 1] : dp[i]; // Skip the word
            }
        }
    }
    
    // The answer will be in dp[0]
    return dp[0];
}