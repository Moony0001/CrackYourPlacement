class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        int pmini = 1;
        int pmaxi = 1;
        int ans = INT_MIN;
        int cmini = 0;
        int cmaxi = 0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                cmini = min(nums[i], nums[i]*pmini);
                cmaxi = max(nums[i], nums[i]*pmaxi);
            }else{
                cmini = min(nums[i], nums[i]*pmaxi);
                cmaxi = max(nums[i], nums[i]*pmini);
            }
            ans = max(ans, cmaxi);
            pmini = cmini;
            pmaxi = cmaxi;
        }
        return ans;
    }
};