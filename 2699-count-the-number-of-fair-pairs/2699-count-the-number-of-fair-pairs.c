int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long count(int *nums, int numsSize, int limit) {
    long res = 0;
    int l = 0, r = numsSize - 1;
    while (l < r) {
        if (nums[l] + nums[r] > limit) {
            r--;
        } else {
            res += r - l;
            l++;
        }
    }
    return res;
}

long countFairPairs(int *nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), compare);
    return count(nums, numsSize, upper) - count(nums, numsSize, lower - 1);
}