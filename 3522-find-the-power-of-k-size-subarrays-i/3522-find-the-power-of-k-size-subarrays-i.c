/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
     int* arr = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int g = 0;

    for (int i = 0; i <= numsSize - k; i++) 
    {
        int isConsecutive = 1;
        for (int j = 0; j < k - 1; j++) {
            if (nums[i + j] + 1 != nums[i + j + 1]) {
                isConsecutive = 0;
                break;
            }
        }
        arr[g++] = isConsecutive ? nums[i + k - 1] : -1;
    }
    *returnSize = g;
    return arr;
}