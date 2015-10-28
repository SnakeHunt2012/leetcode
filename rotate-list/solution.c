#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* index;
    int list_length = 1, step;
    
    if (!head || !head->next)
        return head;
    
    for (index = head; index->next; index = index->next)
        ++list_length;

    index->next = head;

    for (step = list_length - (k % list_length); step < 0; step += list_length)
        ;

    for (; step > 0; --step)
        index = index->next;

    head = index->next;
    index->next = NULL;
    return head;
}
