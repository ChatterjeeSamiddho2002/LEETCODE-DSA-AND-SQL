int getLucky(char* s, int k) {
    
    int sum = 0;

    // Step 1: Convert string to the corresponding number and sum digits directly
    for (int i = 0; s[i] != '\0'; i++) {
        int pos = s[i] - 'a' + 1;
        
        // Add the digits of pos directly to the sum
        while (pos > 0) {
            sum += pos % 10;
            pos /= 10;
        }
    }

    // Step 2: Perform the transformation (sum of digits) k-1 times
    for (int i = 1; i < k; i++) {
        sum = sumOfDigits(sum);
    }

    return sum;
}
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}