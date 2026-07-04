class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0;
        int i=0, j=0;
        int n = nums.size();
        int ans = 0;
        while(j<n && i<=j){
            if(nums[j]==0){
                zero++;
            }
            if(zero>k){
                while(i<=j && zero!=k){
                    if(nums[i]==0){
                        zero--;
                    }
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};