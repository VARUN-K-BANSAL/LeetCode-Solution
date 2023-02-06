class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int ans = 0;
        while(people[j] >= limit) {
            j--;
            ans++;
        }

        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                i++;
                j--;
            } else {
                j--;
            }
            ans++;
        }

        return ans;
    }
};