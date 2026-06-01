class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int ans = 0;
        if(n==1) return nums[0];
        while(left<right){
            int mid = left + (right-left)/2;
            if(left==mid){
                ans = min(nums[left],nums[right]);
                break;
            }else if(nums[mid]<nums[left]){
                right = mid;
            }else if(nums[mid]>nums[right]){
                left = mid;
            }else{
                ans = nums[left];
                break;
            }
        }
        return ans;
    }
};