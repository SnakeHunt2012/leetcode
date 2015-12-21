/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int length_a, length_b, delta;
    struct ListNode *link_a, *link_b;
    for (link_a = headA, length_a = 0; link_a; link_a = link_a->next, ++length_a) ;
    for (link_b = headB, length_b = 0; link_b; link_b = link_b->next, ++length_b) ;
    if (length_a > length_b)
        for (delta = length_a - length_b, link_a = headA, link_b = headB; delta > 0; link_a = link_a->next, --delta) ;
    else
        for (delta = length_b - length_a, link_a = headA, link_b = headB; delta > 0; link_b = link_b->next, --delta) ;
    for (; link_a && link_b && link_a != link_b; link_a = link_a->next, link_b = link_b->next) ;
    return link_a;
}
