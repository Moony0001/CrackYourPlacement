class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        int maxi = nums[nums.size()-1];
        int i = mini;
        int j = 0;
        while(i<=maxi){
            if(i!=nums[j]){
                ans.push_back(i);
                i++;
            }else{
                i++;
                j++;
            }
        }
        return ans;
    }
};