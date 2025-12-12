class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int ans = 0;
        while(i<n){
            if(nums[i]==1){
                j = i;
                int temp = 0;
                while(j<n && nums[j]==1){
                    temp++;
                    j++;
                }
                ans = max(ans,temp);
                i = j;
            }
            i++;
        }
        return ans;
    }
};