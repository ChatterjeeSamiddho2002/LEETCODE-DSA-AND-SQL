#define MAX_LENGTH 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

bool isUnique(char** substrings, int count, char* substring) {
    for (int i = 0; i < count; i++) {
        if (strcmp(substrings[i], substring) == 0) {
            return false;
        }
    }
    return true;
}

int backtrack(char* s, int start, char** substrings, int count) {
    if (s[start] == '\0') {
        return count;
    }

    int maxCount = 0;
    char substring[MAX_LENGTH];
    for (int end = start; s[end] != '\0'; end++) {
        strncpy(substring, s + start, end - start + 1);
        substring[end - start + 1] = '\0';

        if (isUnique(substrings, count, substring)) {
            substrings[count] = strdup(substring);
            maxCount = max(maxCount, backtrack(s, end + 1, substrings, count + 1));
            free(substrings[count]);
        }
    }

    return maxCount;
}
int maxUniqueSplit(char* s) {
     char** substrings = malloc(strlen(s) * sizeof(char*));
    int result = backtrack(s, 0, substrings, 0);
    free(substrings);
    return result;
}