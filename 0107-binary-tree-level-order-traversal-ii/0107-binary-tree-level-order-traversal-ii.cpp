/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int depth, vector<vector<int>>& res) {
        if (!root) {
            return;
        }

        if (res.size() <= depth) {
            res.push_back({});
        }

        res[depth].push_back(root->val);
        helper(root->left, depth + 1, res);
        helper(root->right, depth + 1, res);
    };
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        
        helper(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
};