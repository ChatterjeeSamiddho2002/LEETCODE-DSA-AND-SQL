/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // Forward declaration of the helper function
bool dfs(struct ListNode* head, struct TreeNode* root);

// Helper function to check if the linked list matches a downward path in the tree
bool dfs(struct ListNode* head, struct TreeNode* root) {
    if (head == NULL) {
        return true; // Linked list fully matched
    }
    if (root == NULL) {
        return false; // Tree node is NULL before matching all of the list
    }
    if (root->val != head->val) {
        return false; // Values don't match
    }
    
    // Recursively check left and right subtrees
    return dfs(head->next, root->left) || dfs(head->next, root->right);
}
bool isSubPath(struct ListNode* head, struct TreeNode* root) {
        if (root == NULL) {
        return false; // Tree is empty
    }

    // Check if a downward path starting from the current node matches the list
    return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}