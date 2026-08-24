class Solution {
public:
    int solve(int n, vector<int>& memo){
        if(n<0) return 0;
        if(memo[n]!=-1){
            return memo[n];
        }

        return memo[n] = solve(n-1, memo)+solve(n-2, memo);
    }

    int climbStairs(int n) {
        vector<int> memo(n+1, -1);
        memo[0] = 1;
        solve(n, memo);
        return memo[n];
    }
};