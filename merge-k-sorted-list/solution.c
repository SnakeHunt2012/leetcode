/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head, *tail;
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->val < l2->val) {
        head = l1;
        tail = l1;
        l1 = l1->next;
    } else {
        head = l2;
        tail = l2;
        l2 = l2->next;
    }
    
    while (l1 || l2) {
        if (!l1) {
            tail->next = l2;
            return head;
        }
        if (!l2) {
            tail->next = l1;
            return head;
        }
        if (l1->val < l2->val) {
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        } else {
            tail->next = l2;
            tail = tail->next;
            l2 = l2->next;
        }
    }
    tail->next = NULL;
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    int middle = listsSize / 2;
    struct ListNode *left, *right;
    if (listsSize <= 0)
        return NULL;
    if (listsSize == 1)
        return lists[0];
    if (listsSize == 2)
        return mergeTwoLists(lists[0], lists[1]);
    left = mergeKLists(lists, middle);
    right = mergeKLists(lists + middle, listsSize - middle);
    return mergeTwoLists(left, right);
}
