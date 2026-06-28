class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        int cnt = 0;

        vector<bool> nums(n, 1);
        nums[0] = 0; nums[1]=0;
        for(int i=2;i*i<=n;i++){
            if(nums[i]==1){
                for(int j=i*i;j<n;j+=i){
                    nums[j]= 0;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(nums[i]) cnt++;
        }
        return cnt;
    }
};