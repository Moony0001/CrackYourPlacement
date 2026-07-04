class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ones = 0;
        int zero = 0;
        int i=0, j=0;
        int n = nums.size();
        int ans = 0;
        while(j<n && i<=j){
            if(nums[j]==1){
                ones++;
            }else{
                zero++;
            }
            if(zero>k){
                while(i<=j && zero!=k){
                    if(nums[i]==1){
                        ones--;
                    }else{
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