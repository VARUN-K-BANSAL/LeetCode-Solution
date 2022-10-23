class Solution {
public:
    int findTheWinner(int n, int k) {
        queue <int> q;
        for(int i=0; i<n; i++) {
            q.push(i+1);
        }
        
        while(q.size() != 1) {
            int m = k;
            while(m > 1) {
                int temp = q.front();
                q.pop();
                q.push(temp);
                m--;
            }
            q.pop();
        }
        
        return q.front();
    }
};