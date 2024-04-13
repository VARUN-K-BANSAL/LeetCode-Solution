/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Map<Integer, Node> hm;
    public int[] visited;
    public void dfs(Node node) {
        if(node == null || visited[node.val] == 1) return;
        visited[node.val] = 1;
        hm.put(node.val, new Node(node.val));
        for(int i=0; i<node.neighbors.size(); i++) dfs(node.neighbors.get(i));
    }
    public void solve(Node node) {
        if(node == null || visited[node.val] == 1) return;
        visited[node.val] = 1;
        for(int i=0; i<node.neighbors.size(); i++) {
            int val1 = node.val;
            int val2 = node.neighbors.get(i).val;
            Node n1 = hm.get(val1);
            Node n2 = hm.get(val2);
            n1.neighbors.add(n2);
            // n2.neighbors.add(n1);
            solve(node.neighbors.get(i));
        }
    }
    public Node cloneGraph(Node node) {
        hm = new HashMap<>();
        visited = new int[101];
        dfs(node);
        visited = new int[101];
        solve(node);
        return node == null ? null : hm.get(node.val);
    }
}