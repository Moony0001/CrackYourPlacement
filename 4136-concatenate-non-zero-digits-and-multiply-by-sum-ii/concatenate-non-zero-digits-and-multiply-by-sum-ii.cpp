class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = s.size();
        int m = queries.size();
        int MOD = 1000000007;

        vector<long long> pow10 (n+1, 1);
        for(int i=1;i<=n;i++){
            pow10[i] = (pow10[i-1]*10)%MOD;
        }

        vector<long long> prenum (n, 0);
        vector<int> cnt (n, 0);
        vector<long long> presum (n, 0);

        presum[0] = s[0]-'0';
        if(presum[0]!=0){
            cnt[0] = 1;
            prenum[0] = presum[0];
        }

        for(int i=1;i<n;i++){
            int d = s[i]-'0';
            presum[i] = presum[i-1]+d;
            cnt[i] = cnt[i-1];
            prenum[i] = prenum[i-1];

            if(d!=0){
                cnt[i]++;
                prenum[i] = (prenum[i-1]*10 + d)%MOD;
            }
        }

        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            long long sum = presum[r] - (l>0 ? presum[l-1] : 0);
            int k = cnt[r] - (l>0 ? cnt[l-1] : 0);
            long long rnum = prenum[r];
            long long lnum = (l>0 ? prenum[l-1] : 0);

            long long xnum = (rnum - (lnum*pow10[k]) % MOD + MOD) % MOD;
            long long prod = (xnum * (sum%MOD)) % MOD;
            ans.push_back(prod);
        }
        return ans;
    }
};