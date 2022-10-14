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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode *slow = head;
        ListNode* fast = head->next;
        bool flag = false;
        while(1) {
            if(fast == NULL) {
                break;
            }
            if(fast->next == NULL){
                flag = true;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if(!flag) {
            slow->val = slow->next->val;
        }
        slow->next = slow->next->next;
        return head;
    }
};