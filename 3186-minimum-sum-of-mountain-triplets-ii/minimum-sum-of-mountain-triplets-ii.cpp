class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> premin(n,INT_MAX);
        vector<int> sufmin(n,INT_MAX);
        for(int i=1;i<n;i++){
            premin[i] = min(premin[i-1],nums[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            sufmin[i] = min(sufmin[i+1], nums[i+1]);
        }
        int ans = INT_MAX;
        int flag = 0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>premin[i] && nums[i]>sufmin[i]){
                flag = 1;
                ans = min(ans, nums[i]+premin[i]+sufmin[i]);
            }
        }
        if(flag){
            return ans;
        }
        return -1;
    }
};