class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = k-1;
        int ans = INT_MAX;
        while(j<n){
            ans = min(ans, nums[j]-nums[i]);
            j++; i++;
        }
        return ans;
    }
};