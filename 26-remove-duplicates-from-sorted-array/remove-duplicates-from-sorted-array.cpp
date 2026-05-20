class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = i+1;
        int n = nums.size();
        int ans = 0;
        while(i<n && j<n){
            while(j<n && nums[i]==nums[j]){
                j++;
            }
            if(i+1<n && j<n){
                swap(nums[i+1], nums[j]);
                ans++;
            }
            i++;
            j++;
        }
        return ans+1;
    }
};