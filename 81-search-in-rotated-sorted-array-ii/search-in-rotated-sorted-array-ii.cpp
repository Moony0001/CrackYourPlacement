class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]==nums[left] && nums[mid]==nums[right]){
                left++;
                right--;
            }else if(nums[mid]>=nums[left]){
                if(nums[left]<=target && nums[mid]>target){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{
                if(nums[right]>=target && nums[mid]<target){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return false;
    }
};