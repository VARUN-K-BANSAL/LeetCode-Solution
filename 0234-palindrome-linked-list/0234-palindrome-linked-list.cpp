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
    bool isPalindrome(ListNode* head) {
        string s = "";
        while(head != NULL) {
            s += to_string(head->val);
            head = head->next;
        }
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return s == s1;
    }
};