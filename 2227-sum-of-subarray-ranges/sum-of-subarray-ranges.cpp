class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int j=i;j<n;j++){
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                sum = (sum+(maxi-mini));
            }
        }
        return sum;
    }
};