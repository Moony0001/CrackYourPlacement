class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(n+1, 0);
        if(nums[0]==target) pre[1] = 1;
        for(int i=1;i<n;i++){
            if(nums[i]==target){
                pre[i+1] = pre[i]+1;
            }else{
                pre[i+1] = pre[i];
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len = j-i+1;
                int cnt = pre[j+1]-pre[i];
                if(2*cnt > len){
                    ans++;
                }
            }
        }
        return ans;
    }
};