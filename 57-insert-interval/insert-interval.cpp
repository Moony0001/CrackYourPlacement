class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& comp) {
        vector<vector<int>> ans;
        int n = nums.size();
        int i=0;
        //Phase 1: Everything that comes before the comparing interval we add to ans
        while(i<n && nums[i][1]<comp[0]){
            ans.push_back(nums[i]);
            i++;
        }

        //Phase 2: Everything that is merging with the comparing interval, we merge it and then we finally add it
        while(i<n && nums[i][0]<=comp[1]){
            comp[0] = min(comp[0], nums[i][0]);
            comp[1] = max(comp[1], nums[i][1]);
            i++;
        }
        ans.push_back(comp);

        //Phase 3: Everything that is left over is simply pushed into the answer
        while(i<n){
            ans.push_back(nums[i]);
            i++;
        }

        return ans;
    }
};