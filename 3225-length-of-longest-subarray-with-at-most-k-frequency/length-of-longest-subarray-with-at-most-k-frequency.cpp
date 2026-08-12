class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();

        int i=0, j=0;
        int ans = 0;
        while(j<n){
            if(!mp.count(nums[j]) || mp.count(nums[j]) && mp[nums[j]]<k){
                mp[nums[j]]++;
                j++;
            }else{
                ans = max(ans, (j-i));
                while(i<j && nums[i]!=nums[j]){
                    mp[nums[i]]--;
                    i++;
                }
                mp[nums[i]]--;
                i++;
            }
        }
        ans = max(ans, (j-i));
        return ans;
    }
};