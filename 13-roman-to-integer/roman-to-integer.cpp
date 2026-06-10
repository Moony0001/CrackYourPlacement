class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int i = n - 1;
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
        int ans = 0;
        while (i >= 0) {
            if (s[i] == 'I') {
                ans += mp[s[i]];
                i--;
            } else if (s[i] == 'V' || s[i] == 'X') {
                if (i - 1 >= 0) {
                    if (s[i - 1] == 'I') {
                        ans += (mp[s[i]] - 1);
                        i -= 2;
                    } else {
                        ans += mp[s[i]];
                        i--;
                    }
                } else {
                    ans += mp[s[i]];
                    i--;
                }
            } else if (s[i] == 'L' || s[i] == 'C') {
                if (i - 1 >= 0) {
                    if (s[i - 1] == 'X') {
                        ans += (mp[s[i]] - 10);
                        i -= 2;
                    } else {
                        ans += mp[s[i]];
                        i--;
                    }
                } else {
                    ans += mp[s[i]];
                    i--;
                }
            } else if (s[i] == 'D' || s[i] == 'M') {
                if (i - 1 >= 0) {
                    if (s[i - 1] == 'C') {
                        ans += (mp[s[i]] - 100);
                        i -= 2;
                    } else {
                        ans += mp[s[i]];
                        i--;
                    }
                } else {
                    ans += mp[s[i]];
                    i--;
                }
            }
        }
        return ans;
    }
};