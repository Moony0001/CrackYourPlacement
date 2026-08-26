class Solution {
public:
    int solve(vector<vector<int>>& nums, vector<vector<int>>& memo, int prev, int i){
        if(i>=nums.size()) return 0;

        if(memo[i][prev+1]!=-1){
            return memo[i][prev+1];
        }

        int skip = solve(nums, memo, prev, i+1);

        int take = 0;
        if(prev==-1 || nums[i][0] > nums[prev][1]){
            take = 1 + solve(nums, memo, i, i+1);
        }
        return memo[i][prev+1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return solve(pairs, memo, -1, 0);
    }
};