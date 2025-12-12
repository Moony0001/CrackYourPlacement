class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        long long n = nums.size();
        int cntl = 0;
        long long cntsq = 0;
        for(int i=0;i<n;i++){
            cntl+=nums[i];
            cntsq+=(nums[i]*nums[i]);
        }
        int suml = n*(n+1)/2;
        long long sumsq = n*(2*n+1)*(n+1)/6;
        int amb = suml-cntl;
        int asmbs = sumsq-cntsq;
        int apb = asmbs/amb;
        int a = (amb+apb)/2;
        int b = apb-a;
        ans[0] = b;
        ans[1] = a;
        return ans;
    }
};