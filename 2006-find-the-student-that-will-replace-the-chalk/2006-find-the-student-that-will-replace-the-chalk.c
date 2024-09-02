int chalkReplacer(int* chalk, int chalkSize, int k) {
        long long total = 0;

    // Step 1: Calculate the total chalk requirement for one full round
    for (int i = 0; i < chalkSize; i++) {
        total += chalk[i];
    }

    // Step 2: Reduce k by modulo total
    k %= total;

    // Step 3: Find the student who will replace the chalk
    for (int i = 0; i < chalkSize; i++) {
        if (k < chalk[i]) {
            return i;
        }
        k -= chalk[i];
    }

    // We should never reach this line because one student will always run out of chalk
    return -1;
}