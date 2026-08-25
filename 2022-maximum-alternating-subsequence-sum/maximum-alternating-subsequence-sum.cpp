class Solution {
public:
    typedef long long ll;
    int n;
    
    ll solve(int i, vector<int>& nums, vector<vector<ll>>& memo, bool flag){
        if(i>=n) return 0;
        if(memo[i][flag]!=-1){
            return memo[i][flag];
        }

        ll skip = solve(i+1, nums, memo, flag);
        ll val = nums[i];
        if(flag==false){
            val = -val;
        }
        
        ll take = solve(i+1, nums, memo, !flag) + val;
        return memo[i][flag] = max(skip, take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        vector<vector<ll>> memo(n+1, vector<ll>(2, -1));
        return solve(0, nums, memo, true);
    }
};