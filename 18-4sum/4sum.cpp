class Solution {
public:


    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j-1]==nums[j]) continue;
                for(int k=j+1;k<n-1;k++){
                    if(k>j+1 && nums[k-1]==nums[k]) continue;
                    long long sum = (long long)nums[i]+nums[j]+nums[k];
                    long long find = target-sum;
                    auto it = lower_bound(nums.begin()+k+1, nums.end(), find);
                    int ind = it - nums.begin();
                    if(ind==n || nums[ind]!=find) continue;
                    ans.push_back({nums[i], nums[j], nums[k], nums[ind]});
                }
            }
        }
        return ans;
    }
};