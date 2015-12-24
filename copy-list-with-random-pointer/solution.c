/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *link, *node;
    if (!head)
        return NULL;
    for (link = head; link; link = node->next) {
        node = malloc(sizeof *node);
        node->label = link->label;
        node->next = link->next;
        link->next = node;
    }

    for (link = head; link; link = link->next->next)
        link->next->random = link->random ? link->random->next : NULL;
    
    link = head;
    head = head->next;
    node = head;
    link->next = link->next->next;
    link = link->next;
    while (link) {
        node->next = link->next;
        link->next = link->next->next;
        link = link->next;
        node = node->next;
    }
    node->next = NULL;
    return head;
}
