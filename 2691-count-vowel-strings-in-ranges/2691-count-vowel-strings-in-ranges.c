/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
     int* prefix = (int*)calloc(wordsSize + 1, sizeof(int));  // Prefix sum array
    int* result = (int*)malloc(queriesSize * sizeof(int));   // Result array
    *returnSize = queriesSize;
    
    // Build prefix sum array
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        int len = strlen(word);
        
        // Check if the current word starts and ends with a vowel
        if (isVowel(word[0]) && isVowel(word[len - 1])) {
            prefix[i + 1] = prefix[i] + 1;
        } else {
            prefix[i + 1] = prefix[i];
        }
    }
    
    // Process each query
    for (int i = 0; i < queriesSize; i++) {
        int li = queries[i][0];
        int ri = queries[i][1];
        
        result[i] = prefix[ri + 1] - prefix[li];
    }
    
    free(prefix);
    return result;   
}