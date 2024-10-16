char* longestDiverseString(int a, int b, int c) {
char* result = (char*)malloc(1000); // Allocate a large enough buffer
    int index = 0;
    
    while (a > 0 || b > 0 || c > 0) {
        // Determine the maximum character to add
        if (a >= b && a >= c) {
            // Check if we can add 'a'
            if (index >= 2 && result[index - 1] == 'a' && result[index - 2] == 'a') {
                // Can't add 'a', so try 'b' or 'c'
                if (b >= c) {
                    if (b > 0) {
                        result[index++] = 'b';
                        b--;
                    } else {
                        break;
                    }
                } else {
                    if (c > 0) {
                        result[index++] = 'c';
                        c--;
                    } else {
                        break;
                    }
                }
            } else {
                result[index++] = 'a';
                a--;
            }
        } else if (b >= a && b >= c) {
            // Check if we can add 'b'
            if (index >= 2 && result[index - 1] == 'b' && result[index - 2] == 'b') {
                // Can't add 'b', so try 'a' or 'c'
                if (a >= c) {
                    if (a > 0) {
                        result[index++] = 'a';
                        a--;
                    } else {
                        break;
                    }
                } else {
                    if (c > 0) {
                        result[index++] = 'c';
                        c--;
                    } else {
                        break;
                    }
                }
            } else {
                result[index++] = 'b';
                b--;
            }
        } else {
            // Check if we can add 'c'
            if (index >= 2 && result[index - 1] == 'c' && result[index - 2] == 'c') {
                // Can't add 'c', so try 'a' or 'b'
                if (a >= b) {
                    if (a > 0) {
                        result[index++] = 'a';
                        a--;
                    } else {
                        break;
                    }
                } else {
                    if (b > 0) {
                        result[index++] = 'b';
                        b--;
                    } else {
                        break;
                    }
                }
            } else {
                result[index++] = 'c';
                c--;
            }
        }
    }
    
    result[index] = '\0'; // Null-terminate the string
    return result;
}