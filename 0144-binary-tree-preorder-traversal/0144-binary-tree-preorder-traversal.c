/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void preorder(struct TreeNode* root, int* arr, int* index) {
    // Base case: if the node is NULL, return
    if (root == NULL) {
        return;
    }
    // Store the current node's value in the array
    arr[*index] = root->val;
    (*index)++;

    // Recursively traverse the left subtree
    preorder(root->left, arr, index);

    // Recursively traverse the right subtree
    preorder(root->right, arr, index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
 // Allocate memory for the array to store traversal result
    int* arr = (int*)malloc(100 * sizeof(int));  // Assume a max size of 100 nodes for now
    int index = 0;

    // Perform preorder traversal and store values in the array
    preorder(root, arr, &index);

    // Set the returnSize to the number of nodes visited
    *returnSize = index;

    // Reallocate the array to the actual size of nodes visited
    arr = (int*)realloc(arr, index * sizeof(int));

    return arr;
} 
