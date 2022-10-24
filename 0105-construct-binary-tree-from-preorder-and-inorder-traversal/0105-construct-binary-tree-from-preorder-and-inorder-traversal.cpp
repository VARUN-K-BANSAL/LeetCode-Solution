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
    int pre = 0;
    int preMax = -1;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preMax = preorder.size() - 1;
        return helper(preorder, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int a, int b) {
        if(pre > preMax || a > b) return NULL;
        if(a == b) return new TreeNode(preorder[pre++]);
        pre++;
        int temp = a;
        while(temp <= b) {
            if(preorder[pre-1] == inorder[temp]) {
                break;
            }
            temp++;
        }
        TreeNode *root = new TreeNode(preorder[pre-1]);
        root->left = helper(preorder, inorder, a, temp - 1);
        root->right = helper(preorder, inorder, temp + 1, b);
        return root;
    }
};