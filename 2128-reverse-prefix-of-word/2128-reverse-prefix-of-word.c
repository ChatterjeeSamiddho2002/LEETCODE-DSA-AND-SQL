char* reversePrefix(char* word, char ch) {
    int i = 0;
// Find the first occurrence of ch
    while (word[i] && word[i] != ch) {
        i++;
    }
// If ch is not found, return the original word
    if (word[i] != ch) {
        return word;
    }
// Reverse from index 0 to i
    int left = 0, right = i;
    while (left < right) {
        char temp = word[left];
        word[left] = word[right];
        word[right] = temp;
        left++;
        right--;
    }
return word;
}