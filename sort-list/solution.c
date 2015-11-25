#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode *link;

link merge(link a, link b)
{
    link head, tail = NULL;
    while (a && b)
        if (a->val < b->val) {
            if (tail) {
                tail->next = a;
                tail = tail->next;
            } else {
                head = tail = a;
            }
            a = a->next;
        } else {
            if (tail) {
                tail->next = b;
                tail = tail->next;
            } else {
                head = tail = b;
            }
            b = b->next;
        }
    tail->next = a ? a : b;
    return head;
}

struct ListNode* sortList(struct ListNode* head) {
    link a, b, c;
    if (!head || !head->next)
        return head;
    for (a = c = head, b = head->next; b && b->next; c = c->next, b = b->next->next) ;
    b = c->next;
    c->next = NULL;
    return merge(sortList(a), sortList(b));
}
