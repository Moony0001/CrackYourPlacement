class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 1;
        int right = nums[n-1]+k;
        int ans = -1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            auto it = upper_bound(nums.begin(), nums.end(), mid);
            int ind = 0;
            ind = it - nums.begin();
            int cnt = mid-ind;
            if(cnt >= k){
                ans = mid;
                right = mid-1;
            }else if(cnt < k){
                left = mid+1;
            }
        }
        return ans;
    }
};