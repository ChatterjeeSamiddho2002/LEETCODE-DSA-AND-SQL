/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int isNumber(const char* s) {
    for (int i = 0; s[i]; i++) {
        if (!isdigit(s[i])) return 0;
    }
    return 1;
}
void addResult(int** results, int* resultSize, int value) {
    *results = realloc(*results, (*resultSize + 1) * sizeof(int));
    (*results)[(*resultSize)++] = value;
}
int* diffWaysToCompute(char* expression, int* returnSize) {
    int n = strlen(expression);
    *returnSize = 0;
    
    // Base case: If the expression is just a number
    if (isNumber(expression)) {
        int* result = malloc(sizeof(int));
        result[0] = atoi(expression); // Convert string to integer
        *returnSize = 1;
        return result;
    }

    int* results = NULL; // Initialize results as NULL
    for (int i = 0; i < n; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            // Recursively compute results for the left and right sub-expressions
            
            // Left sub-expression
            int leftSize = 0;
            char leftPart[i + 1];
            strncpy(leftPart, expression, i);
            leftPart[i] = '\0';
            int* leftResults = diffWaysToCompute(leftPart, &leftSize);
            
            // Right sub-expression
            int rightSize = 0;
            char* rightPart = expression + i + 1;
            int* rightResults = diffWaysToCompute(rightPart, &rightSize);

            // Combine results from left and right sub-expressions based on the current operator
            for (int j = 0; j < leftSize; j++) {
                for (int k = 0; k < rightSize; k++) {
                    int left = leftResults[j];
                    int right = rightResults[k];
                    int result;

                    if (expression[i] == '+') {
                        result = left + right;
                    } else if (expression[i] == '-') {
                        result = left - right;
                    } else if (expression[i] == '*') {
                        result = left * right;
                    }

                    // Dynamically add the result using the helper function
                    addResult(&results, returnSize, result);
                }
            }

            // Free the dynamically allocated memory for left and right results
            free(leftResults);
            free(rightResults);
        }
    }

    return results;
}