class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = 0;
        for(int i : nums){
            total += i;
        }
        int n = nums.size();
        vector<int> ans(n,0);
        int left = 0;
        for(int i=0;i<n;i++){
            left+=nums[i];
            ans[i] = abs((left-nums[i])-(total-left));
        }
        return ans;
    }
};