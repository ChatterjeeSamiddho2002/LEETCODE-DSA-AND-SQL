bool canArrange(int* arr, int arrSize, int k) {
        int remainderCount[k];
    
    // Initialize the remainder count array to 0
    for (int i = 0; i < k; i++) {
        remainderCount[i] = 0;
    }
    
    // Count the remainders
    for (int i = 0; i < arrSize; i++) {
        int remainder = arr[i] % k;
        if (remainder < 0) {
            remainder += k;  // Handle negative numbers
        }
        remainderCount[remainder]++;
    }
    
    // Check pairs
    for (int i = 0; i <= k / 2; i++) {
        if (i == 0) {
            // The count of elements divisible by k (remainder 0) must be even
            if (remainderCount[i] % 2 != 0) {
                return false;
            }
        } else {
            // The count of elements with remainder i must match the count with remainder k-i
            if (remainderCount[i] != remainderCount[k - i]) {
                return false;
            }
        }
    }
    
    return true;
}
