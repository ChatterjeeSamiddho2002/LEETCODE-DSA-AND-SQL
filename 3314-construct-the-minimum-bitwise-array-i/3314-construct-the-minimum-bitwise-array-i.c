/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for (int idx = 0; idx < numsSize; idx++) {
        int i = nums[idx];
        if (i & 1) {
            int bit = ((i + 1) & ~i) >> 1;
            res[idx] = i & ~bit;
        } else {
            res[idx] = -1;
        }
    }
    return res;
}