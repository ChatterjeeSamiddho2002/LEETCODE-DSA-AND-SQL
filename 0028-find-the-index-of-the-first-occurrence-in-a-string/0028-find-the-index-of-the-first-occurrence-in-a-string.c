int strStr(char* haystack, char* needle) {
    int x=strlen(haystack);
    int y=strlen(needle);
        if (y>x) {
        return -1;
    }
    
    
    for (int i = 0; i <= x-y; i++) {
        int j = 0;
        
        while (j < y && haystack[i + j] == needle[j]) {
            j++;
        }
        
        if (j == y) {
            return i;
        }
    }
    
    
    return -1;
}
