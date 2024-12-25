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
 struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};
void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (q->rear) {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    if (!q->front) {
        q->front = newNode;
    }
}

// Helper function to dequeue
struct TreeNode* dequeue(struct Queue* q) {
    if (!q->front) return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->node;
    q->front = q->front->next;
    if (!q->front) {
        q->rear = NULL;
    }
    free(temp);
    return node;
}
int* largestValues(struct TreeNode* root, int* returnSize) {
   if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct Queue q = {NULL, NULL};
    enqueue(&q, root);

    int* result = (int*)malloc(1000 * sizeof(int));  // Allocate enough space
    int levelSize, maxVal, index = 0;

    while (q.front) {
        levelSize = 0;
        maxVal = INT_MIN;

        // Count nodes at the current level
        struct QueueNode* temp = q.front;
        while (temp) {
            levelSize++;
            temp = temp->next;
        }

        // Process each node at this level
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(&q);
            if (node->val > maxVal) {
                maxVal = node->val;
            }
            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }
        result[index++] = maxVal;
    }

    *returnSize = index;
    return result;  
}