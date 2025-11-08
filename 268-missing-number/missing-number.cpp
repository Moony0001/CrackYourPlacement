class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long c = n*(n+1)/2;
        int sum = 0;
        for(int t: nums){
            sum+=t;
        }
        int ans = c-sum;
        return ans;
    }
};