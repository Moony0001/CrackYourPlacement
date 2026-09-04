class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        int sum = 0;
        int ans = 0;
        for(int i : nums){
            sum += i;
            if(sum==k){
                ans++;
            }
            int temp = sum-k;
            if(mp.count(temp)){
                ans += mp[temp].size();
            }
            mp[sum].push_back(i);
        }
        return ans;
    }
};