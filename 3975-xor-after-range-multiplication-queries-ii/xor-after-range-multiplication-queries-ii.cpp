class Solution {
    int MOD = 1e9 + 7;

    // Helper function for Modular Exponentiation
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Helper function for Modular Inverse (Replaces standard division)
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = 316; // Approx sqrt(10^5)

        // diff[k][i] will store the difference array logic for step size k
        vector<vector<int>> diff(B, vector<int>(n, 1));

        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= B) {
                // Large steps: Pure simulation is O(sqrt(N)) and very fast
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (nums[idx] * 1LL * v) % MOD;
                }
            } else {
                // Small steps: Use the specialized Difference Array
                diff[k][l] = (diff[k][l] * 1LL * v) % MOD;
                
                // Calculate the exact index where this jump sequence stops
                int steps = (r - l) / k;
                int stop_idx = l + (steps + 1) * k;
                
                // Instead of dividing, we multiply by the modular inverse
                if (stop_idx < n) {
                    diff[k][stop_idx] = (diff[k][stop_idx] * 1LL * modInverse(v)) % MOD;
                }
            }
        }

        // Push the difference array values forward by their respective step sizes
        for (int k = 1; k < B; k++) {
            for (int i = k; i < n; i++) {
                diff[k][i] = (diff[k][i] * 1LL * diff[k][i - k]) % MOD;
            }
        }

        int final_xor = 0;

        // Apply all the accumulated multipliers to the original array
        for (int i = 0; i < n; i++) {
            long long multiplier = 1;
            for (int k = 1; k < B; k++) {
                multiplier = (multiplier * diff[k][i]) % MOD;
            }
            
            nums[i] = (nums[i] * multiplier) % MOD;
            final_xor ^= nums[i];
        }

        return final_xor;
    }
};