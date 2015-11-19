/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head_one = malloc(sizeof(*head_one));
    struct ListNode *head_two = malloc(sizeof(*head_two));
    struct ListNode *index, *link;

    head_one->next = l1;
    head_two->next = l2;

    while (head_one->next) {
        for (index = head_two; index->next; index = index->next)
            if (index->next->val > head_one->next->val)
                break;
        link = head_one->next;
        head_one->next = head_one->next->next;
        link->next = index->next;
        index->next = link;
        printf("here\n");
    }

    link = head_two->next;
    free(head_one);
    free(head_two);
    return link;
}
