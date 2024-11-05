int min(int a, int b) {
    return (a < b) ? a : b;
}

int minChanges(char* s) {
    int n = strlen(s);
    int result = 0;
    
    // Process pairs of characters
    for (int i = 0; i < n; i += 2) {
        // Count changes needed if making current pair 00
        int changes_to_00 = (s[i] == '0' ? 0 : 1) + (s[i + 1] == '0' ? 0 : 1);
        // Count changes needed if making current pair 11
        int changes_to_11 = (s[i] == '1' ? 0 : 1) + (s[i + 1] == '1' ? 0 : 1);
        
        // For each pair, we can make it either 00 or 11
        result += fmin(changes_to_00, changes_to_11);
    }
    
    return result;
}