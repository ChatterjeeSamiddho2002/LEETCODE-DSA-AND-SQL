/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
      struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* first = dummy;
    struct ListNode* second = dummy;
    
    // Move first pointer n+1 steps ahead
    for (int i = 0; i < n + 1; i++) {
        if (first == NULL) return head; // Handle case where n is larger than list length
        first = first->next;
    }
    
    // Move both pointers until first reaches the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    
    // Remove the nth node from the end
    struct ListNode* temp = second->next;
    second->next = temp->next;
    free(temp);
    
    // Get the new head and free the dummy node
    struct ListNode* newHead = dummy->next;
    free(dummy);
    
    return newHead;
}