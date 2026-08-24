class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n+1, -1);

        memo[0] = 0;
        memo[1] = nums[0];

        for(int i=2;i<=n;i++){
            memo[i] = max(nums[i-1]+memo[i-2], memo[i-1]);
        }
        return memo[n];
    }
};