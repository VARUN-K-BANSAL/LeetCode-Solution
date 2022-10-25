class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& v1, vector<string>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        
        string s1 = "";
        string s2 = "";
        for(int i=0; i<n1; i++) {
            s1 += v1[i];
        }
        for(int i=0; i<n2; i++) {
            s2 += v2[i];
        }
        
        return s1 == s2;
    }
};