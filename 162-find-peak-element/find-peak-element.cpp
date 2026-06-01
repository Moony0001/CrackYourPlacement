class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int left = 0;
        int right = n-1;
        int ans = 0;

        while(left<=right){
            int mid = left + (right-left)/2;

            if((mid==0 && nums[mid]>nums[mid+1]) || (mid==n-1 && nums[mid]>nums[mid-1]) || (mid>0 && mid<n && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])){
                ans = mid;
                break;
            }else if(nums[left]>nums[mid]){
                if(nums[right]>nums[left]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }else if(nums[right]>nums[mid]){
                if(nums[left]>nums[right]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{
                left++;
                right--;
            }
        }
        return ans;
    }
};