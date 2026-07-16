class Solution {
public:
    long long gcd(long long a, long long b){
        if(b==0){
            return a;
        }
        
        return gcd(b, a%b);
    }

    long long gcdSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        vector<long long> pre (n,0);

        for(int i=0;i<n;i++){
            maxi = max(maxi, nums[i]);
            long long g = gcd(maxi, nums[i]);
            pre[i] = g;
        }

        sort(pre.begin(), pre.end());

        int i=0, j=n-1;
        long long ans =0;
        while(i<j){
            ans = ans + gcd(pre[i], pre[j]);
            i++;
            j--;
        }
        return ans;
    }
};