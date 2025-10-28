class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre (n,0);
        vector<int> suf (n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i] = nums[i]+pre[i-1];
        }
        suf[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = suf[i+1]+nums[i];
        }

        if(suf[0]==0){
            int x = 2*n;
            return x;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(pre[i]==suf[i]){
                    ans+=2;
                }else if(abs(pre[i]-suf[i])==1){
                    ans+=1;
                }
            }
            
        }
        return ans;
    }
};