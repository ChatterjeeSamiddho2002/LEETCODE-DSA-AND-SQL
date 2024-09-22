int findKthNumber(int n, int k) {
        int curr = 1;
    k--; // Decrease k to account for 0-based index

    while (k > 0) {
        long long steps = 0;
        long long first = curr;
        long long last = curr + 1;

        while (first <= n) {
            steps += fmin((long long)n + 1, last) - first;
            first *= 10;
            last *= 10;
        }

        if (steps > k) {
            curr *= 10;
            k--;
        } else {
            curr++;
            k -= steps;
        }
    }

    return curr;
}
