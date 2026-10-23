

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#ifdef LOCAL_TEST
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
#endif

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while (curr) {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;       
        curr = next;
    }
    return prev;
}

#ifdef LOCAL_TEST
int main(void) {
    struct ListNode nodes[] = {{1, NULL}, {2, NULL}, {3, NULL}, {4, NULL}, {5, NULL}};
    for (int i = 0; i < 4; ++i) {
        nodes[i].next = &nodes[i + 1];
    }

    struct ListNode *reversed = reverseList(nodes);
    while (reversed) {
        printf("%d%s", reversed->val, reversed->next ? " -> " : "\n");
        reversed = reversed->next;
    }
    return 0;
}
#endif