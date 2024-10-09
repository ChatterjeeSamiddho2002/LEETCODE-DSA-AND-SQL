int minAddToMakeValid(char* s) {
     int stack = 0;  // Use an integer as a stack to count open parentheses
    int moves = 0;  // Count of necessary moves

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack++;  // Push to stack
        } else if (s[i] == ')') {
            if (stack > 0) {
                stack--;  // Pop from stack
            } else {
                moves++;  // Need to add an opening parenthesis
            }
        }
    }

    moves += stack;  // Add remaining open parentheses to moves

    return moves;
}