/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
     int totalSum = mean * (rollsSize + n);
    int currentSum = 0;
    for (int i = 0; i < rollsSize; i++) {
        currentSum += rolls[i];
    }
    
    int missingSum = totalSum - currentSum;
    if (missingSum < n || missingSum > 6 * n) {
        *returnSize = 0;
        return NULL;
    }
    
    int* result = (int*)malloc(n * sizeof(int));
    int avg = missingSum / n;
    int remainder = missingSum % n;
    
    for (int i = 0; i < n; i++) {
        result[i] = avg + (i < remainder ? 1 : 0);
    }
    
    *returnSize = n;
    return result;

}