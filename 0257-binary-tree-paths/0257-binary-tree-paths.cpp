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
    
    void helper(vector<string> &v, TreeNode *root, string s) {
        if(!root->left && !root->right) {
            v.push_back(s);
            return;
        }
        
        if(root->left) helper(v, root->left, s + "->" + to_string(root->left->val));
        if(root->right) helper(v, root->right, s + "->" + to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(!root) return v;
        
        helper(v, root, to_string(root->val));
        return v;
    }
};