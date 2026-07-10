class Solution {
public:
    int candy(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> child (n, 1);
        
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                child[i] = child[i-1] + 1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                child[i] = max(child[i],child[i+1] + 1);
            }
        }
        for(int i : child){
            ans += i;
        }
        return ans;
    }
};