class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==2){
                ans[i]=-1;
            }else{
                long long x = nums[i];
                long long st = 0;
                while(x&1){
                    st = st*2 + 1;
                    x = x>>1;
                }
                x = nums[i];
                ans[i] = x - st + (st>>1);
            }
        }
        return ans;
    }
};