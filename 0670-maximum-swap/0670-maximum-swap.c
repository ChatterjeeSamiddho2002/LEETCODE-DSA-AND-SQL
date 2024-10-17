int maximumSwap(int num) {
    char numStr[11]; // To store the number as a string (max 10 digits + 1 for null terminator)
    sprintf(numStr, "%d", num); // Convert integer to string
    int len = strlen(numStr);
    
    // Create an array to store the last occurrence of each digit
    int last[10];
    for (int i = 0; i < 10; i++) {
        last[i] = -1; // Initialize to -1
    }
    
    for (int i = 0; i < len; i++) {
        last[numStr[i] - '0'] = i; // Store the last occurrence of each digit
    }
    
    // Try to find the first digit that can be swapped to maximize the number
    for (int i = 0; i < len; i++) {
        // Check for a larger digit that appears later
        for (int d = 9; d > numStr[i] - '0'; d--) {
            if (last[d] > i) {
                // Swap the digits
                char temp = numStr[i];
                numStr[i] = numStr[last[d]];
                numStr[last[d]] = temp;
                // Convert back to integer and return
                return atoi(numStr);
            }
        }
    }
    
    // If no swap was made, return the original number
    return num;
}