#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// We need to return both the count of valid numbers and the waviness sum
struct Result {
    long long count;
    long long waviness;
};

class Solution {
private:
    // dp[idx][tight][lz][prev1][prev2]
    // We use size 11 for prev1/prev2 so index 10 can represent "No Digit Yet"
    Result dp[20][2][2][11][11];
    string R;

    Result solve(int idx, bool tight, bool lz, int prev1, int prev2) {
        // Base Case: We have filled all digits.
        // This represents 1 valid number, which adds 0 new waviness at the very end.
        if (idx == R.length()) {
            return {1, 0};
        }

        // Return cached result if we've already computed this exact state
        if (dp[idx][tight][lz][prev1][prev2].count != -1) {
            return dp[idx][tight][lz][prev1][prev2];
        }

        int limit = tight ? (R[idx] - '0') : 9;
        Result ans = {0, 0};

        // Try placing every valid digit from 0 to 'limit'
        for (int d = 0; d <= limit; d++) {
            
            bool next_tight = tight && (d == limit);
            bool next_lz = lz && (d == 0);
            
            // If we are still in leading zeros, don't update prev1 and prev2
            int next_prev1 = next_lz ? 10 : d;
            int next_prev2 = next_lz ? 10 : prev1;

            // Recursively solve for the remaining digits
            Result res = solve(idx + 1, next_tight, next_lz, next_prev1, next_prev2);

            long long current_added_waviness = 0;
            
            // If we have at least 3 real digits, check for a peak or valley
            if (!lz && prev1 != 10 && prev2 != 10) {
                // Peak Check
                if (prev1 > prev2 && prev1 > d) current_added_waviness = 1;
                // Valley Check
                if (prev1 < prev2 && prev1 < d) current_added_waviness = 1;
            }

            // 1. Add the raw count of valid suffixes
            ans.count += res.count;
            
            // 2. The total waviness is the waviness generated deep in the recursion (res.waviness)
            // PLUS the peak/valley we just found, multiplied by the number of suffixes it applies to!
            ans.waviness += res.waviness + (current_added_waviness * res.count);
        }

        // Cache and return
        return dp[idx][tight][lz][prev1][prev2] = ans;
    }

    // Helper function to calculate total waviness from 0 to N
    long long calculateUpTo(long long n) {
        if (n < 100) return 0; // Constraints say < 3 digits have 0 waviness
        
        R = to_string(n);
        
        // Reset the memoization table with -1
        // We cast the struct pointer to fill it with -1 bytes
        memset(dp, -1, sizeof(dp)); 
        
        // Start: idx=0, tight=true, lz=true, prev1=10 (none), prev2=10 (none)
        return solve(0, true, true, 10, 10).waviness;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        // Standard Prefix Logic: Range[L, R] = UpTo(R) - UpTo(L - 1)
        return calculateUpTo(num2) - calculateUpTo(num1 - 1);
    }
};