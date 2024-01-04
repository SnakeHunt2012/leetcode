/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
    struct ListNode* next;
    
    if (!head) return head;

    next = removeNodes(head->next);
    if (next && next->val > head->val) return next;
    
    head->next = next;
    return head;
}
