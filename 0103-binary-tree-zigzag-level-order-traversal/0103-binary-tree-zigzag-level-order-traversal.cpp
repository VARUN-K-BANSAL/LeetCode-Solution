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
    vector<vector<int>> v;
    int count = 0;
    int height(TreeNode *root) {
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return (lh > rh) ? lh+1 : rh+1;
    }

    void printLevel(TreeNode *root, int level) {
        if(!root) { return; }
        if(level == 1) v[count].push_back(root->val);
        else if(level > 1) {
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
    }

    void levelorderTraversal(TreeNode *root) {
        if(root == NULL) return;
        int h = height(root);
        for(int i=1; i<=h; i++) {
            v.push_back({});
            printLevel(root, i);
            count++;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> x;
        if(root == NULL) return x;
        if(root->left == NULL && root->right == NULL) {
            vector<int> temp;
            temp.push_back(root->val);
            x.push_back(temp);
            return x;
        }
        levelorderTraversal(root);
        int n = v.size();
        for(int i=1; i<n; i+=2) {
            reverse(v[i].begin(), v[i].end());
        }
        return v;
    }
};