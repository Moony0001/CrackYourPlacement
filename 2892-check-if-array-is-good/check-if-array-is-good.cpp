class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=1;i<=n-1;i++){
            if(nums[i-1]!=i){
                return false;
            }
        }
        if(nums[n-1]!=n-1){
            return false;
        }
        return true;
    }
};