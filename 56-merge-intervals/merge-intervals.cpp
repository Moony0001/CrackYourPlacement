class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i=0, j=i+1;
        while(i<n && j<n){
            if(nums[i][1] >= nums[j][0]){
                nums[i][1] = max(nums[j][1], nums[i][1]);
                j++;
            }else{
                ans.push_back(nums[i]);
                i = j;
                j++;
            }            
        }
        ans.push_back(nums[i]);
        return ans;
    }
};