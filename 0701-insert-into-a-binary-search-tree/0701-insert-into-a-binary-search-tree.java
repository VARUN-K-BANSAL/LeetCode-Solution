/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if(root == null) return new TreeNode(val);
        TreeNode itr = root;
        while(itr != null) {
            if(itr.left == null && itr.val > val) {
                TreeNode newNode = new TreeNode(val);
                itr.left = newNode;
                break;
            }
            if(itr.right == null && itr.val < val) {
                TreeNode newNode = new TreeNode(val);
                itr.right = newNode;
                break;
            }
            
            if(itr.val < val) itr = itr.right;
            else itr = itr.left;
        }
        
        return root;
    }
}