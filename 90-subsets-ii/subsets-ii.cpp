class Solution {
public:

    void sub(vector<vector<int>>& ans, vector<int>& nums, vector<int>& can, int i){
        if(i==nums.size()){
            ans.push_back(can);
            return;
        }
        can.push_back(nums[i]);
        sub(ans, nums, can, i+1);
        can.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        sub(ans, nums, can, i+1);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> can;
        sort(nums.begin(), nums.end());
        sub(ans, nums, can, 0);
        return ans;
    }
};