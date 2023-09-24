class Solution {
    public long maximumSumOfHeights(List<Integer> A) {
        int n = A.size();
        long[] left = new long[n];
        long[] right = new long[n];
        
        Stack<Integer> st = new Stack<>();
        left[0] = A.get(0);
        st.push(0);
        for(int i=1; i<n; i++) {
            if(A.get(i) <= A.get(st.peek())) {
                while(!st.empty() && A.get(st.peek()) >= A.get(i)) {
                    st.pop();
                }
                if(st.empty()) {
                    left[i] = (i + 1) * 1L * A.get(i);
                } else {
                    left[i] = left[st.peek()] + (i - st.peek()) * 1L * A.get(i);
                }
            } else {
                left[i] = left[i-1] + 1L * A.get(i);
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        right[n-1] = A.get(n-1);
        st.push(n-1);
        for(int i=n-2; i>=0; i--) {
            if(A.get(i) <= A.get(st.peek())) {
                while(!st.empty() && A.get(st.peek()) >= A.get(i)) {
                    st.pop();
                }
                if(st.empty()) {
                    right[i] = (n - i) * 1L * A.get(i);
                } else {
                    right[i] = right[st.peek()] + (st.peek() - i) * 1L * A.get(i);
                }
            } else {
                right[i] = right[i+1] + 1L * A.get(i);
            }
            st.push(i);
        }
        
        for(int i=0; i<n; i++)
            System.out.print(left[i] + " ");
        
        System.out.println("");
        for(int i=0; i<n; i++)
            System.out.print(right[i] + " ");
        
        long ans = -1;
        for(int i=0; i<n; i++) {
            long temp = left[i] + right[i] - A.get(i);
            // ans = Math.max(ans, temp);
            if(temp > ans) {
                System.out.println("Index i : " + i);
                ans = temp;
            }
        }
        
        return ans;
    }
}