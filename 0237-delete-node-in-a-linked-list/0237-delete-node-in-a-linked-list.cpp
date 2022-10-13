/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        // ListNode* temp = node->next;
        // ListNode* prev = node;
        // while(temp != NULL && temp->next != NULL) {
        //     int v = temp->val;
        //     temp->val = prev->val;
        //     prev->val = v;
        //     prev = prev->next;
        //     temp = temp->next;
        // }
        // prev->val = temp->val;
        // prev->next = NULL;
    }
};