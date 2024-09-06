/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// Hashing helper functions to create a hash set
#define MAX_HASH 100007

bool hashSet[MAX_HASH];

void addToSet(int value) {
    hashSet[value % MAX_HASH] = true;
}

bool existsInSet(int value) {
    return hashSet[value % MAX_HASH];
}

// Function to modify the linked list by removing nodes whose values are in the set
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    // Initialize the hash set with all false values
    for (int i = 0; i < MAX_HASH; i++) {
        hashSet[i] = false;
    }
    
    // Add all nums elements to the hash set
    for (int i = 0; i < numsSize; i++) {
        addToSet(nums[i]);
    }

    // Dummy node to handle cases where the head needs to be removed
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode* current = dummy;
    
    while (current->next != NULL) {
        if (existsInSet(current->next->val)) {
            // Remove the node by skipping it
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp); // Free the removed node's memory
        } else {
            // Move to the next node
            current = current->next;
        }
    }
    
    struct ListNode* newHead = dummy->next;
    free(dummy); // Free the dummy node's memory
    
    return newHead;
}

// Helper function to create a new ListNode
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}