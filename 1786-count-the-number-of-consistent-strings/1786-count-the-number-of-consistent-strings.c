

int countConsistentStrings(char * allowed, char ** words, int wordsSize){
 bool allowedChars[26] = {false};  // Array to mark allowed characters
    
    // Mark the characters that are allowed
    for (int i = 0; allowed[i] != '\0'; i++) {
        allowedChars[allowed[i] - 'a'] = true;
    }
    
    int count = 0;  // To count consistent strings
    
    // Iterate through each word in the words array
    for (int i = 0; i < wordsSize; i++) {
        bool isConsistent = true;
        
        // Check if all characters in the word are in the allowed set
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (!allowedChars[words[i][j] - 'a']) {
                isConsistent = false;  // If a character is not allowed, mark as inconsistent
                break;
            }
        }
        
        if (isConsistent) {
            count++;  // Increment the count if the word is consistent
        }
    }
    
    return count;
}