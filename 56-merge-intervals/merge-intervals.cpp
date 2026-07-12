class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i=0;
        int j=1;
        int last = 0;
        while(i<n && j<n){
            if(max(nums[i][1], nums[j][0])==nums[i][1]){
                nums[i][0] = min(nums[i][0], nums[j][0]);
                nums[i][1] = max(nums[i][1], nums[j][1]);
                j++;
            }else{
                nums[last][0] = nums[i][0];
                nums[last][1] = nums[i][1];
                last++;
                i = j;
                j++;
            }
        }

        nums[last][0] = nums[i][0];
        nums[last][1] = nums[i][1];
        last++;
        i++;

        vector<vector<int>> ans;
        ans.assign(nums.begin(), nums.begin()+last);
        return ans;
    }
};