class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int i = n - 1;
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
        int ans = 0;
        int maxi = 0;
        while (i >= 0) {
            int curr = mp[s[i]];
            if (curr < maxi) {
                ans -= curr;
            } else {
                ans += curr;
                maxi = max(maxi, curr);
            }
            i--;
        }
        return ans;
    }
};