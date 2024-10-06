#define MAX_WORDS 100
int split_sentence(char* sentence, char words[MAX_WORDS][MAX_WORDS]) {
    int word_count = 0;
    char* token = strtok(sentence, " ");
    
    while (token != NULL) {
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, " ");
    }
    
    return word_count;
}
bool areSentencesSimilar(char* sentence1, char* sentence2) {
    char words1[MAX_WORDS][MAX_WORDS], words2[MAX_WORDS][MAX_WORDS];
    
    // Split both sentences into words
    char temp1[MAX_WORDS * MAX_WORDS];
    char temp2[MAX_WORDS * MAX_WORDS];
    
    strcpy(temp1, sentence1);
    strcpy(temp2, sentence2);
    
    int count1 = split_sentence(temp1, words1);
    int count2 = split_sentence(temp2, words2);
    
    int i = 0, j = 0;
    
    // Compare prefix (from the start)
    while (i < count1 && i < count2 && strcmp(words1[i], words2[i]) == 0) {
        i++;
    }
    
    // Compare suffix (from the end)
    while (j < count1 - i && j < count2 - i && strcmp(words1[count1 - 1 - j], words2[count2 - 1 - j]) == 0) {
        j++;
    }
    
    // Check if the remaining words can be inserted
    return i + j >= (count1 < count2 ? count1 : count2);
}