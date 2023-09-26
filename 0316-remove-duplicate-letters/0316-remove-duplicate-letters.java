class Solution {
    public String removeDuplicateLetters(String a) {
        char[] s = a.toCharArray();
        int n = a.length();
        int last[] = new int[26];
        for(int i=0; i<n; i++) {
            last[s[i] - 'a'] = i;
        }
        
        Stack<Character> st = new Stack<>();
        boolean[] visited = new boolean[26];
        for(int i=0; i<n; i++) {
            if(visited[s[i] - 'a']) continue;
            while(!st.empty() && st.peek() > s[i] && last[st.peek() - 'a'] > i) {
                visited[st.pop() - 'a'] = false;
            }
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        
        StringBuilder sb = new StringBuilder();
        while(!st.empty()) {
            sb.append(st.peek());
            st.pop();
        }
        
        return sb.reverse().toString();
        
//         char[] a = s.toCharArray();
//         int n = s.length();
//         int freq[] = new int[26];
//         int count = 0;
//         for(int i=n-1; i>=0; i--) {
//             if(freq[a[i] - 'a'] > 0) {
//                 a[i] = '#';
//                 count++;
//             } else {
//                 freq[a[i] - 'a']++;
//             }
//         }
        
//         char res[] = new char[n - count];
//         int k = 0;
//         for(int i=0; i<n; i++) {
//             if(a[i] != '#') {
//                 res[k++] = a[i];
//             }
//         }
        
//         return new String(res);
    }
}