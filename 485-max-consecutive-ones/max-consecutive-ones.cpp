class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        int ans = 0;
        while(i<n){
            int cnt = 0;
            if(nums[i]==1){
                while(i<n && nums[i]==1){
                    cnt++;
                    i++;
                }
                ans = max(ans,cnt);
            }
            i++;
        }
        return ans;
    }
};