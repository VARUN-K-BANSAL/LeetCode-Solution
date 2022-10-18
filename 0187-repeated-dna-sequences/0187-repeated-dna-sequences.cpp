class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        if(s.size() < 10) return v;
        
        unordered_map<string, int> mp;
        for(int i=0; i<s.size() - 9; i++) {
            mp[s.substr(i, 10)]++;
        }
        
        for(auto x : mp) {
            if(x.second > 1) v.push_back(x.first);
        }
        return v;
    }
};