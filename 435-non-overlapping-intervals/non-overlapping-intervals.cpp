class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int currend = nums[0][1];
        int ans = 0;
        for(int i=1;i<n;i++){
            if(currend > nums[i][0]){
                ans++;
                currend = min(currend, nums[i][1]);
            }else{
                currend = nums[i][1];
            }
        }
        return ans;
    }
};