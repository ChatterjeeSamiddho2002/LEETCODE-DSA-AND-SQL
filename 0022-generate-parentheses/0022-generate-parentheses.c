/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
        char** result = NULL;
    *returnSize = 0;

    char* combination = (char*)malloc((2 * n + 1) * sizeof(char));
    if (!combination) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    backtrack(0, 0, 0, n, combination, &result, returnSize);
    free(combination);

    return result;
}
void addCombination(char*** result, int* returnSize, char* combination) {
    (*result) = (char**)realloc(*result, (*returnSize + 1) * sizeof(char*));
    (*result)[*returnSize] = strdup(combination);
    (*returnSize)++;
}

// Recursive backtracking function
void backtrack(int open, int close, int index, int n, char* combination, char*** result, int* returnSize) {
    // Base case: if the combination is complete
    if (index == 2 * n) {
        combination[index] = '\0';
        addCombination(result, returnSize, combination);
        return;
    }

    // Add an open parenthesis if there are still open parentheses available
    if (open < n) {
        combination[index] = '(';
        backtrack(open + 1, close, index + 1, n, combination, result, returnSize);
    }

    // Add a close parenthesis if it doesn't exceed the number of open parentheses
    if (close < open) {
        combination[index] = ')';
        backtrack(open, close + 1, index + 1, n, combination, result, returnSize);
    }
}

