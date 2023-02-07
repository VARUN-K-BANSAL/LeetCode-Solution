class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n <= 2) return n;
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        for(; j < n; j++) {
            mp[fruits[j]]++;
            if(mp.size() > 2) {
                if(--mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
        }
        
        return j - i;
    }
};