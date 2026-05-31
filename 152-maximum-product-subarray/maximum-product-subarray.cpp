class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[0][0] = 1;
        dp[0][1] = 1;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                dp[i+1][0] = min(nums[i], nums[i]*dp[i][0]);
                dp[i+1][1] = max(nums[i], nums[i]*dp[i][1]);
            }else{
                dp[i+1][0] = min(nums[i], nums[i]*dp[i][1]);
                dp[i+1][1] = max(nums[i], nums[i]*dp[i][0]);
            }
            ans = max(ans, dp[i+1][1]);
        }
        return ans;
    }
};