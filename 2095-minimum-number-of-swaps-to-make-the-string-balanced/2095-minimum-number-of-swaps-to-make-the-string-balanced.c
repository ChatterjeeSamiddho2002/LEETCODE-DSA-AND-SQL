int minSwaps(char* s) {
     int imbalance = 0;  // Tracks the current imbalance between '[' and ']'
    int maxImbalance = 0;  // Tracks the maximum imbalance observed

    // Traverse the string to calculate imbalance
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '[') {
            imbalance--;  // Decrease imbalance when encountering an opening bracket
        } else {
            imbalance++;  // Increase imbalance when encountering a closing bracket
        }

        // Track the maximum imbalance (we care only about positive imbalance)
        if (imbalance > maxImbalance) {
            maxImbalance = imbalance;
        }
    }

    // The number of swaps required is half of the maximum imbalance
    // A swap can fix 2 unbalanced brackets, so divide the max imbalance by 2
    return (maxImbalance + 1) / 2;
}