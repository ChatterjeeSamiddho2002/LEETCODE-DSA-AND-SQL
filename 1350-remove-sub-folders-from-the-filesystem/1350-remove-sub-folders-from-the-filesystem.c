/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
  // Sort the folder array
    qsort(folder, folderSize, sizeof(char *), compare);
    
    char **result = malloc(folderSize * sizeof(char *));
    int resultIndex = 0;
    
    for (int i = 0; i < folderSize; i++) {
        // If the result is empty or the current folder is not a sub-folder of the last added folder
        if (resultIndex == 0 || strncmp(result[resultIndex - 1], folder[i], strlen(result[resultIndex - 1])) || folder[i][strlen(result[resultIndex - 1])] != '/') {
            result[resultIndex++] = folder[i];
        }
    }
    
    *returnSize = resultIndex;
    return result;  
}