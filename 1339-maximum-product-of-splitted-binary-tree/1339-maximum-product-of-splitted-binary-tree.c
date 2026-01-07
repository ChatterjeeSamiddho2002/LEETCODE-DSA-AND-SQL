/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
long long total, best;
const int MOD = 1000000007;

long long sum(struct TreeNode* node) {
    if (!node) return 0;
    return node->val + sum(node->left) + sum(node->right);
}

long long dfs(struct TreeNode* node) {
    if (!node) return 0;
    long long s = node->val + dfs(node->left) + dfs(node->right);
    long long prod = s * (total - s);
    if (prod > best) best = prod;
    return s;
}

int maxProduct(struct TreeNode* root) {
    total = sum(root);
    best = 0;
    dfs(root);
    return best % MOD;
}