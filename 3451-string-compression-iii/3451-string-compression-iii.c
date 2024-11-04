char* compressedString(char* word) {
     int len = strlen(word);
    char* comp = malloc(len * 2 + 1); // Allocate enough space for compressed string
    if (!comp) return NULL; // Check for allocation failure

    int i = 0, j = 0;

    while (i < len) {
        char c = word[i];
        int count = 0;

        // Count consecutive characters, up to a maximum of 9
        while (i < len && word[i] == c && count < 9) {
            count++;
            i++;
        }

        // Append count and character to the compressed string
        j += sprintf(comp + j, "%d%c", count, c);
    }

    return comp;
}