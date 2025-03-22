/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = 0;
    node->next = NULL;
    struct ListNode* curr = node;
    int carry = 0;
    while(l1!=NULL || l2!=NULL || carry!=0) {
        int x = (l1!=NULL) ? l1->val : 0;
        int y = (l2!=NULL) ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum/10;
        curr->next = malloc(sizeof(struct ListNode));
        curr->next->val = sum%10;
        curr->next->next = NULL;
        curr = curr->next;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    struct ListNode* result = node->next;
    free(node);
    return result;
}