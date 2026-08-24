class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev1 = 0;
        int prev2 = nums[0];
        int ans = prev2;

        for(int i=2;i<=n;i++){
            ans = max(nums[i-1]+prev1, prev2);
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};