/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    // Step 1: Initialize the matrix with -1
    int** matrix = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = -1;
        }
    }
    
    *returnSize = m;
    
    // Step 2: Set up the boundaries
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    
    struct ListNode* current = head;
    
    // Step 3: Traverse the matrix in spiral order
    while (top <= bottom && left <= right && current != NULL) {
        // Traverse from left to right
        for (int i = left; i <= right && current != NULL; i++) {
            matrix[top][i] = current->val;
            current = current->next;
        }
        top++;  // Move the top boundary down
        
        // Traverse from top to bottom
        for (int i = top; i <= bottom && current != NULL; i++) {
            matrix[i][right] = current->val;
            current = current->next;
        }
        right--;  // Move the right boundary left
        
        // Traverse from right to left
        for (int i = right; i >= left && current != NULL; i--) {
            matrix[bottom][i] = current->val;
            current = current->next;
        }
        bottom--;  // Move the bottom boundary up
        
        // Traverse from bottom to top
        for (int i = bottom; i >= top && current != NULL; i--) {
            matrix[i][left] = current->val;
            current = current->next;
        }
        left++;  // Move the left boundary right
    }
    
    return matrix;
}