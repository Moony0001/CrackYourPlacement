class Solution {
public:
    int solve(vector<int>& nums, vector<int>& memo, int i){
        if(i>=nums.size()) return 0;

        if(memo[i]!=-1){
            return memo[i];
        }

        int steal = nums[i] + solve(nums, memo, i+2);
        int skip = solve(nums, memo, i+1);

        return memo[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n+1, -1);
        return solve(nums, memo, 0);
    }
};