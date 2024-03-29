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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *itr = head->next;
        head->next = NULL;
        while(itr->next != NULL) {
            ListNode *temp = itr->next;
            itr->next = head;
            head = itr;
            itr = temp;
            temp = itr->next;
        }
        
        itr->next = head;
        return itr;
    }
};