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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> nums;
        ListNode *temp = head;
        while(temp != NULL) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> v;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            v.push_back(nums[i]);
        }
        for(int i=0; i<n; i++) {
            v[(i + k) % n] = nums[i];
        }

        ListNode *itr = head;
        for(int i=0; i<n; i++) {
            itr->val = v[i];
            itr = itr->next;
        }

        return head;
    }
};