class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mini = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n/2;i++){
            mini = max(mini, (nums[i]+nums[n-i-1]));
        }
        return mini;
    }
};