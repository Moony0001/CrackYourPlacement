class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        ans += nums[0];
        nums.erase(nums.begin());
        sort(nums.begin(), nums.end());
        ans+= nums[0];
        ans+= nums[1];
        return ans;
    }
};