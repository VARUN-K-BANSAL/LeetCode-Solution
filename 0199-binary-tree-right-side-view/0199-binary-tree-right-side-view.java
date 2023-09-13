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
    public void levelOrder(List<List<Integer>> res, TreeNode root, int height) {
        if(root == null) return;
        if(height >= res.size()) {
            res.add(new LinkedList<Integer>());
        }
        
        res.get(height).add(root.val);
        levelOrder(res, root.left, height + 1);
        levelOrder(res, root.right, height + 1);
    }
    public List<Integer> rightSideView(TreeNode root) {
        List<List<Integer>> levels = new ArrayList<List<Integer>>();
        levelOrder(levels, root, 0);
        
        List<Integer> res = new ArrayList<>();
        for(int i=0; i<levels.size(); i++) {
            res.add(levels.get(i).get(levels.get(i).size() - 1));
        }
        return res;
    }
}