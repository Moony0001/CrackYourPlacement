class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            int cnt = nums[mid] - mid - 1;
            if(cnt >= k){
                right = mid-1;
            }else if(cnt < k){
                left = mid+1;
            }
        }
        return left+k;
    }
};