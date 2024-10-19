char findKthBit(int n, int k) {
 // Base case
    if (n == 1) return '0';

    // Calculate the length of Sn
    int length = (1 << n) - 1; // This is 2^n - 1

    // The middle index (1-based index)
    int mid = (length + 1) / 2;

    if (k == mid) {
        return '1'; // The middle bit is always '1'
    } else if (k < mid) {
        // If k is in the first half
        return findKthBit(n - 1, k);
    } else {
        // If k is in the second half
        // Calculate the index for the inverted and reversed part
        int newK = length - k + 1; // Reflect k around the middle
        char bit = findKthBit(n - 1, newK); // Get the corresponding bit
        return (bit == '0') ? '1' : '0'; // Invert the bit
    }
}
