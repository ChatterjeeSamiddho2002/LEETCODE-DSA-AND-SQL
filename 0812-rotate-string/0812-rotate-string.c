bool rotateString(char* s, char* goal) {
     if (strlen(s) != strlen(goal)) {
        return false;
    }

    // Concatenate s with itself
    char doubleS[2 * strlen(s) + 1];
    strcpy(doubleS, s);
    strcat(doubleS, s);
    
    // Check if goal is a substring of doubleS
    return strstr(doubleS, goal) != NULL;
}