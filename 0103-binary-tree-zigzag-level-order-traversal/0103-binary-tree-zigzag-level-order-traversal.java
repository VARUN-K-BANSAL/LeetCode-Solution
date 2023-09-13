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
    public void helper(List<List<Integer>> res, TreeNode root, int height) {
        if(root == null) return;
        if(height >= res.size()) res.add(new LinkedList<Integer>());
        res.get(height).add(root.val);
        helper(res, root.left, height + 1);
        helper(res, root.right, height + 1);
    }
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        helper(res, root, 0);
        for(int i=1; i<res.size(); i += 2) {
            Collections.reverse(res.get(i));
        }
        return res;
    }
}