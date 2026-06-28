class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1<<n;
        vector<vector<int>> ans;
        ans.reserve(total);

        for(int mask = 0;mask<total;mask++){
            vector<int> temp;
            for(int i=0;i<n;i++){
                if((mask&(1<<i)) !=0){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};