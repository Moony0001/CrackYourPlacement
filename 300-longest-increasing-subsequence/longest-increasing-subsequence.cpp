class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& memo, int i, int prev){
        if(i>=nums.size()){
            return 0;
        }
        
        if(memo[i][prev+1]!=-1){
            return memo[i][prev+1];
        }

        int skip = solve(nums, memo, i+1, prev);

        int pick = 0;
        if(prev==-1 || nums[i] > nums[prev]){
            pick = 1 + solve(nums, memo, i+1, i);
        }
        return memo[i][prev+1] = max(skip, pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return solve(nums, memo, 0, -1);
    }
};