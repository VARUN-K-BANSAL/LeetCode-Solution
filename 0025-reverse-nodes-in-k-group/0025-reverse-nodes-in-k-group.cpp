/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return head;
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int count = 0;
        ListNode *temp = head;
        int c = 0;
        while(temp != NULL) {
            temp = temp->next;
            c++;
        }
        if(c < k) return head;
        while (current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next != NULL)
            head->next = reverseKGroup(next, k);
        return prev;
    }
};