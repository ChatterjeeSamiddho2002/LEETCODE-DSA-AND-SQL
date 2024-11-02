bool isCircularSentence(char* sentence) {
   char temp[1001]; // Assuming the max length of the sentence is 1000 characters
    strcpy(temp, sentence);
    
    // Split the sentence into words
    char *words[1000]; // Assuming a maximum of 100 words
    int count = 0;

    char *word = strtok(temp, " ");
    while (word != NULL) {
        words[count++] = word;
        word = strtok(NULL, " ");
    }

    // Check for circular conditions
    for (int i = 0; i < count; i++) {
        char *current_word = words[i];
        char *next_word = words[(i + 1) % count]; // Wrap around to the first word
        
        if (current_word[strlen(current_word) - 1] != next_word[0]) {
            return false;
        }
    }

    return true;  
}