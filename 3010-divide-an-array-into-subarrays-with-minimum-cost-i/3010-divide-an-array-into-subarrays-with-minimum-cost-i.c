int minimumCost(int* nums, int n) {
    int m1 = 1e9, m2 = 1e9;
    for (int i = 1; i < n; i++) {
        if (nums[i] <= m1) {
            m2 = m1;
            m1 = nums[i];
        } else if (nums[i] < m2) {
            m2 = nums[i];
        }
    }
    return nums[0] + m1 + m2;
}