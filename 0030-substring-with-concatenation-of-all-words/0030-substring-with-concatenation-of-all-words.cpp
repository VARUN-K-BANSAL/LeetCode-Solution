class Solution {
public:
    
    bool helper(unordered_map<string, int> wordCount, string s, int wordLen) {
        for(int j=0; j<s.size(); j+=wordLen) {
            string w = s.substr(j, wordLen);
            if(wordCount.find(w) != wordCount.end()) {
                if(--wordCount[w] == -1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].size();
        int sLen = s.size();
        int wordsWindow = words.size() * wordLen;
        
        unordered_map<string, int> wordCount;
        for(int i=0; i<words.size(); i++) {
            wordCount[words[i]]++;
        }
        
        int i = 0;
        while(i + wordsWindow <= sLen) {
            if(helper(wordCount, s.substr(i, wordsWindow), wordLen)) {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
    
//     bool helper(string s, vector<string>& w) {
//         int n = s.length();
//         int len = w.size();
        
//         map<string, int> mp;
//         for(int i=0; i<len; i++) {
//             mp.insert({w[i], i});
//         }
        
//         bool found = false;
//         int count = 0;
//         for(int i=0; i<n-1; i++) {
//             cout << i << endl;
//             int temp = -1;
//             for(int j=i; j<n; j++) {
//                 if(mp.find(s.substr(i, j)) != mp.end()) {
//                     mp.erase(s.substr(i, j));
//                     found = true;
//                     temp = j;
//                     count++;
//                     break;
//                 }
//             }
//             if(found) {
//                 i = temp;
//                 found = false;
//             }
//         }
        
//         if(count == len) return true;
//         return false;
//     }
    
//     vector<int> findSubstring(string s, vector<string>& words) {
//         int len = words.size();
//         int n = s.length();
//         vector<int> v;
//         int tot = 0;
//         for(int i=0; i<n; i++) tot += words[i].length();
        
//         for(int i=0; i<n - tot; i++) {
//             if(helper(s.substr(i, i+tot), words)) v.push_back(i);
//         }
//         return v;
//     }
};