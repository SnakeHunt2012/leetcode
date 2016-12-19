/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int number = 0;
    struct ListNode *head = NULL, *tail;
    while (l1 || l2 || number > 0) {
        if (l1) {
            number += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            number += l2->val;
            l2 = l2->next;
        }
        if (!head) {
            head = tail = malloc(sizeof(struct ListNode));
            tail->val = number % 10;
            tail->next = NULL;
        } else {
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = number % 10;
            tail->next->next = NULL;
            tail = tail->next;
        }
        number /= 10;
    }
    return head;
}
