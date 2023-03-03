class Solution {
public:
    bool isPresent(string h, string t, int start) {
        int n = t.length();
        for(int i=0; i<n; i++) {
            if(h[start + i] != t[i])
                return false;
        }
        return true;
    }
    int strStr(string hs, string nd) {
        int n = hs.length();
        int n2 = nd.length();
        if(n2 > n)
            return -1;
        for(int i=0; i<n; i++) {
            if(hs[i] == nd[0]) {
                if(isPresent(hs, nd, i))
                    return i;
            }
        }
        
        return -1;
    }
};