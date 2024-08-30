/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
     int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // Create an array of pairs to store both value and index
    typedef struct {
        int value;
        int index;
    } Pair;
    Pair* pairs = (Pair*)malloc(numsSize * sizeof(Pair));

    // Fill the pairs array
    for (int i = 0; i < numsSize; i++) {
        pairs[i].value = nums[i];
        pairs[i].index = i;
    }

    // Sort the pairs array based on values
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (pairs[j].value > pairs[j + 1].value) {
                Pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int sum = pairs[left].value + pairs[right].value;
        if (sum == target) {
            result[0] = pairs[left].index;
            result[1] = pairs[right].index;
            free(pairs);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    // If no solution is found
    *returnSize = 0;
    free(result);
    free(pairs);
    return NULL;
}