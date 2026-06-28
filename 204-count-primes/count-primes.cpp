class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        int cnt = n-1;

        vector<int> nums(n, 1);
        for(int i=2;i*i<=n;i++){
            for(int j=i*i;j<n;j+=i){
                if(nums[j]==1){
                    cnt--;
                    nums[j]=0;
                }
            }
        }
        return cnt-1;
    }
};