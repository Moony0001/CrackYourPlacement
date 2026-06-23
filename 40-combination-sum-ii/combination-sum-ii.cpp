class Solution {
public:

    void subsumk(vector<vector<int>>& ans, vector<int>& can, vector<int>& nums, int sum, int i){
        if(sum==0){
            ans.push_back(can);
            return;
        }
        if(i==nums.size() || sum<0){
            return;
        }
        
        can.push_back(nums[i]);
        subsumk(ans, can, nums, sum-nums[i], i+1);
        can.pop_back();
        //Once we have included a number x in our subsequence, we will not include any of its duplicates again to prevent repetitions
        //So, we skip all the same numbers
        while(i+1<nums.size() && nums[i+1]==nums[i]){
            i++;
        }
        
        subsumk(ans, can, nums, sum, i+1);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> can;
        sort(candidates.begin(), candidates.end());
        subsumk(ans, can, candidates, target, 0);
        return ans;

    }
};