/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
     // If both nodes are null, they are equivalent
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    
    // If one is null and the other is not, they are not equivalent
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    
    // If values do not match, they are not equivalent
    if (root1->val != root2->val) {
        return false;
    }
    
    // Check for both configurations: normal and flipped
    return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
           (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
}
