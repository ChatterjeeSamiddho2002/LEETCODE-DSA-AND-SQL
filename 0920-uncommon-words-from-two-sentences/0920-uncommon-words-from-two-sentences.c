/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void countWords(char* sentence, int* wordMap, char** wordList, int* wordIndex, int* size) {
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < *wordIndex; i++) {
            if (strcmp(wordList[i], word) == 0) {
                wordMap[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            wordList[*wordIndex] = (char*)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(wordList[*wordIndex], word);
            wordMap[*wordIndex]++;
            (*wordIndex)++;
        }
        word = strtok(NULL, " ");
    }
}
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
      // Define a max size for the word list and wordMap
    int maxWords = 200;  // Assumption: total number of words won't exceed this
    int* wordMap = (int*)calloc(maxWords, sizeof(int));  // Frequency of each word
    char** wordList = (char**)malloc(maxWords * sizeof(char*));  // List of unique words
    
    int wordIndex = 0;  // To track the number of unique words

    // Count words in both sentences
    countWords(s1, wordMap, wordList, &wordIndex, returnSize);
    countWords(s2, wordMap, wordList, &wordIndex, returnSize);

    // Find uncommon words (words with a frequency of exactly 1)
    char** uncommonWords = (char**)malloc(maxWords * sizeof(char*));
    int uncommonIndex = 0;
    
    for (int i = 0; i < wordIndex; i++) {
        if (wordMap[i] == 1) {
            uncommonWords[uncommonIndex] = wordList[i];
            uncommonIndex++;
        } else {
            free(wordList[i]);  // Free memory for words that are not uncommon
        }
    }

    free(wordList);
    free(wordMap);
    
    *returnSize = uncommonIndex;
    return uncommonWords;
}