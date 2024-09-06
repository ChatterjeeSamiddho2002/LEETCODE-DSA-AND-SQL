bool isValid(char* s) {
        // Stack to hold opening brackets
    char stack[10000];
    int top = -1;  // Stack pointer

    // Traverse each character in the string
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        // For closing brackets, check if they match the top of the stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                // Stack is empty but we encountered a closing bracket
                return false;
            }
            char topChar = stack[top--];  // Pop from the stack
            
            // Check for corresponding matching brackets
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // If the stack is empty after processing all characters, the string is valid
    return top == -1;
}