class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int i = 0;
        int n = nums.size();
        vector<int> hash(n+1, 0);
        int cnt = 0;
        int ans = 0;
        for(int j=0;j<nums.size();j++){
            if(hash[nums[j]]==0){
                cnt++;
            }
            hash[nums[j]]++;

            while(cnt>k){
                hash[nums[i]]--;
                if(hash[nums[i]]==0){
                    cnt--;
                }
                i++;
            }

            ans += (j-i+1);
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};