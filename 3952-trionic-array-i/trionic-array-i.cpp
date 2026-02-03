class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0;
        int j=1;
        int n = nums.size();
        while(j<n && nums[j]>nums[j-1]){
            j++;
        }
        if(j==1 || j==n){
            return false;
        }

        while(j<n && nums[j]<nums[j-1]){
            j++;
        }
        if(j==n){
            return false;
        }

        while(j<n && nums[j]>nums[j-1]){
            j++;
        }
        if(j!=n){
            return false;
        }
        return true;
    }
};