/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
     // Create a dummy node to act as the starting point of the merged list
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;  // Initialize the dummy node's next pointer to NULL
    
    // Traverse both lists
    while (list1 != NULL && list2 != NULL) {
        // Compare the current nodes of list1 and list2
        if (list1->val <= list2->val) {
            // Attach list1's node to the merged list
            tail->next = list1;
            list1 = list1->next;  // Move the pointer in list1
        } else {
            // Attach list2's node to the merged list
            tail->next = list2;
            list2 = list2->next;  // Move the pointer in list2
        }
        // Move the tail pointer to the next node in the merged list
        tail = tail->next;
    }
    
    // If either list1 or list2 still has nodes left, attach them to the merged list
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }
    
    // Return the merged list, which starts after the dummy node
    return dummy.next;
}