class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<long long>> dp (n+1, vector<long long>(2, 0));
        long long preveven = 0;
        long long prevodd = 0;

        for(int i=1;i<=n;i++){
            long long tempodd = max(preveven+nums[i-1], prevodd);
            long long tempeven = max(prevodd-nums[i-1], preveven);

            prevodd = tempodd;
            preveven = tempeven;
        }

        return max(preveven, prevodd);
    }
};