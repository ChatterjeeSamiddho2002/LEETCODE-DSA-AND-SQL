#define MOD 1000000007
int numWays(char** words, int wordsSize, char* target) {
     int wordLen = strlen(words[0]);
    int targetLen = strlen(target);
    
    // Step 1: Create a frequency table
    int freq[wordLen][26];
    memset(freq, 0, sizeof(freq));
    
    // Fill frequency table
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordLen; j++) {
            freq[j][words[i][j] - 'a']++;
        }
    }
    
    // Step 2: Dynamic programming table
    long dp[targetLen + 1][wordLen + 1];
    memset(dp, 0, sizeof(dp));
    
    // Base case: 1 way to form the empty prefix of the target
    for (int j = 0; j <= wordLen; j++) {
        dp[0][j] = 1;
    }
    
    // Step 3: Fill DP table
    for (int i = 1; i <= targetLen; i++) {
        char targetChar = target[i - 1];
        for (int j = 1; j <= wordLen; j++) {
            // Carry over previous ways
            dp[i][j] = dp[i][j - 1];
            
            // If current character can contribute to the target
            int charIndex = targetChar - 'a';
            if (freq[j - 1][charIndex] > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * freq[j - 1][charIndex]) % MOD;
            }
        }
    }
    
    return (int)dp[targetLen][wordLen];
}