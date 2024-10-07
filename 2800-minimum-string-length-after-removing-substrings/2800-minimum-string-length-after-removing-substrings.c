int minLength(char * s){
    int n = strlen(s);
    char stack[n]; // Stack to simulate the removal process
    int top = -1;  // Stack pointer

    // Traverse through each character in the string
    for (int i = 0; i < n; i++) {
        if (top >= 0 && ((stack[top] == 'A' && s[i] == 'B') || (stack[top] == 'C' && s[i] == 'D'))) {
            // If top of the stack forms "AB" or "CD" with current character, pop the stack
            top--;
        } else {
            // Otherwise, push the current character onto the stack
            stack[++top] = s[i];
        }
    }

    // The length of the stack represents the minimum length of the resulting string
    return top + 1;
}