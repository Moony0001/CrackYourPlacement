class Solution {
public:
    int pnp(string& s, vector<vector<int>>& memo, int i, string& t, int j){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;

        int cnt = 0;
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(s[i]==t[j]){
            cnt += pnp(s, memo, i+1, t, j+1);
        }
        cnt += pnp(s, memo, i+1, t, j);

        return memo[i][j] = cnt;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> memo (s.size(), vector<int>(t.size(), -1));

        return pnp(s, memo, 0, t, 0);

    }
};