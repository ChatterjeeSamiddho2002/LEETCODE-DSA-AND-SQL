int memo[2001][21];  // 2001 for sum offsets (-1000 to 1000), 21 for numsSize <= 20

int dfs(int* nums, int numsSize, int index, int sum, int target) {
    // Base case: if we've processed all numbers
    if (index == numsSize) {
        return (sum == target) ? 1 : 0;
    }
    
    // Check memoization table
    if (memo[sum + 1000][index] != -1) {
        return memo[sum + 1000][index];
    }
    
    // Explore both adding and subtracting the current number
    int add = dfs(nums, numsSize, index + 1, sum + nums[index], target);
    int subtract = dfs(nums, numsSize, index + 1, sum - nums[index], target);
    
    // Store the result in memoization table
    memo[sum + 1000][index] = add + subtract;
    
    return memo[sum + 1000][index];
}
int findTargetSumWays(int* nums, int numsSize, int target) {
       // Initialize memoization table to -1
    memset(memo, -1, sizeof(memo));
    
    // Start DFS from index 0 with sum 0
    return dfs(nums, numsSize, 0, 0, target); 
}