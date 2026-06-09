class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = INT_MIN;
        long long mini = INT_MAX;

        for(long long i : nums){
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
        long long ans = (maxi-mini)*k;
        return ans;
    }
};