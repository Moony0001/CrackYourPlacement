class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        if(n==1) return true;
        vector<int> reach (n, 0);
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                reach[i] = i+nums[i];
                maxi = max(maxi, reach[i]);
            }else{
                if((i!=n-1 && maxi<=i) || (i==n-1 && maxi<i)){
                    return false;
                }
                reach[i] = 0;
            }
        }
        return true;
    }
};