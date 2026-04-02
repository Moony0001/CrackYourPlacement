class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k] where k is the number of neutralizations used (0, 1, or 2)
        // Initialize with a very small number since profits can be negative
        long long INF = -1e18;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, INF)));
        
        // Base case: starting cell (0, 0)
        dp[0][0][0] = coins[0][0]; 
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0; // Use 1st neutralization right at the start
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                
                for (int k = 0; k < 3; ++k) {
                    // Find the best path coming from the Top or Left using 'k' neutralizations
                    long long best_prev = INF;
                    if (i > 0) best_prev = max(best_prev, dp[i-1][j][k]);
                    if (j > 0) best_prev = max(best_prev, dp[i][j-1][k]);
                    
                    if (best_prev != INF) {
                        // Option 1: Just take the cell's value (whether positive or negative)
                        dp[i][j][k] = max(dp[i][j][k], best_prev + coins[i][j]);
                    }
                    
                    // Option 2: If it's a robber, and we CAN use a neutralization (k > 0)
                    if (coins[i][j] < 0 && k > 0) {
                        long long best_prev_minus_one = INF;
                        if (i > 0) best_prev_minus_one = max(best_prev_minus_one, dp[i-1][j][k-1]);
                        if (j > 0) best_prev_minus_one = max(best_prev_minus_one, dp[i][j-1][k-1]);
                        
                        if (best_prev_minus_one != INF) {
                            // We neutralize it, so we add 0 instead of the negative coin value
                            dp[i][j][k] = max(dp[i][j][k], best_prev_minus_one + 0);
                        }
                    }
                }
            }
        }
        
        // The answer is the maximum profit at the bottom-right cell, 
        // whether we used 0, 1, or 2 neutralizations.
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};