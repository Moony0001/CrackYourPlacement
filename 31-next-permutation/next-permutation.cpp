class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int tempi = 0;
        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                tempi = i;
                break;
            }
        }
        swap(nums[ind], nums[tempi]);
        reverse(nums.begin()+ind+1, nums.end());
    }
};