class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        for(int& i : nums){
            i = abs(i);
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long pos = 0;
        long long neg = 0;
        int i = 0;
        while(i<n/2){
            neg += nums[i]*nums[i];
            i++;
        }
        while(i<n){
            pos += nums[i]*nums[i];
            i++;
        }
        ans = pos - neg;
        return ans;
    }
};