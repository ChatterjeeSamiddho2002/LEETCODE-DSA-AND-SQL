int sumFourDivisors(int* nums, int numsSize) {
    int totalSum = 0;

    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        int count = 0;
        int sum = 0;

        for (int d = 1; d <= n; d++) {
            if (n % d == 0) {
                count++;
                sum += d;
            }

            // If divisors are already more than 4, stop
            if (count > 4) {
                break;
            }
        }

        if (count == 4) {
            totalSum += sum;
        }
    }

    return totalSum;
}
