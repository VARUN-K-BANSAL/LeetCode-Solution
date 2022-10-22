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
    int a[10001] = {0};
    int count = 0;
    void traversal(TreeNode* root) {
        if(!root) return;
        traversal(root->left);
        a[count++] = root->val;
        traversal(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        traversal(root);
        return a[k - 1];
    }
};