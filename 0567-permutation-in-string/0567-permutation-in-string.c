bool checkInclusion(char* s1, char* s2) {
   int len1 = strlen(s1), len2 = strlen(s2);
    
    if (len1 > len2) return false;
    
    // Frequency arrays for s1 and current window in s2
    int s1Freq[26] = {0};
    int s2Freq[26] = {0};
    
    // Populate the frequency array for s1
    for (int i = 0; i < len1; i++) {
        s1Freq[s1[i] - 'a']++;
        s2Freq[s2[i] - 'a']++;  // also initialize the first window in s2
    }
    
    // Compare the frequency arrays
    bool matches = true;
    for (int i = 0; i < 26; i++) {
        if (s1Freq[i] != s2Freq[i]) {
            matches = false;
            break;
        }
    }
    if (matches) return true;
    
    // Sliding window
    for (int i = len1; i < len2; i++) {
        // Slide the window: add the next character and remove the old one
        s2Freq[s2[i] - 'a']++;
        s2Freq[s2[i - len1] - 'a']--;
        
        // Compare the updated frequency arrays
        matches = true;
        for (int j = 0; j < 26; j++) {
            if (s1Freq[j] != s2Freq[j]) {
                matches = false;
                break;
            }
        }
        if (matches) return true;
    }
    
    return false; 
}