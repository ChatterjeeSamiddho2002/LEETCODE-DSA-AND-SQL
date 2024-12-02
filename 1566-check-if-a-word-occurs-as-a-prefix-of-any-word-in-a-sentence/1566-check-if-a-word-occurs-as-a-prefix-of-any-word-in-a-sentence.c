int isPrefixOfWord(char* sentence, char* searchWord) {
   int index = 1;  // 1-based index for words
    char* word = strtok(sentence, " ");  // Split the sentence by spaces

    // Iterate through each word in the sentence
    while (word != NULL) {
        // Check if searchWord is a prefix of the current word
        if (strncmp(word, searchWord, strlen(searchWord)) == 0) {
            return index;  // Return the index (1-based) of the first match
        }
        word = strtok(NULL, " ");  // Move to the next word
        index++;  // Increment the word index
    }

    return -1;  // Return -1 if no match is found 
}