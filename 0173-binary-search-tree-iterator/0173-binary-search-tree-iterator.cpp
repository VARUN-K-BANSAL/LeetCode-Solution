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
class BSTIterator {
public:
    int a[100001] = {0};
    int count = 0;
    int n = 0;
    void traversal(TreeNode *root) {
        if(!root) return;
        traversal(root->left);
        a[count++] = root->val;
        traversal(root->right);
    }
    BSTIterator(TreeNode* root) {
        traversal(root);
    }
    
    int next() {
        if(n < count) return a[n++];
        return -1;
    }
    
    bool hasNext() {
        if(n < count) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */