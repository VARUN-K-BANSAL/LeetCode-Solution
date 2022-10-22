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
    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode *temp = head;
        while(temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int start = 0;
        int end = v.size() - 1;
        while(start < end) {
            if(start + 2 == end) {
                head->val = v[start];
                head->next->val = v[end--];
                head->next->next->val = v[start + 1];
                break;
            }
            head->val = v[start++];
            head->next->val = v[end--];
            head = head->next->next;
        }
    }
};