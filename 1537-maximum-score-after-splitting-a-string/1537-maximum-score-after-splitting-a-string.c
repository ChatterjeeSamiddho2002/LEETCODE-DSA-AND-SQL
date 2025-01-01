int maxScore(char* s) {
    int n = strlen(s);
    int max = 0;
    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            y++;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') {
            x++;
        } else {
            y--;
        }
        if (x + y > max) {
            max = x + y;
        }
    }

    return max;
}