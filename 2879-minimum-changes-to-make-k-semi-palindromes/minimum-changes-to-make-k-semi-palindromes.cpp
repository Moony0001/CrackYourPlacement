class Solution {
public:
    int getchangeford(string& s, int left, int right, int d) {
        int changes = 0;
        for (int start = 0; start < d; start++) {
            int p1 = left + start;
            int p2 = left + start;
            while (p2 + d <= right) {
                p2 += d;
            }
            while (p1 < p2) {
                if (s[p1] != s[p2]) {
                    changes++;
                }
                p1 += d;
                p2 -= d;
            }
        }
        return changes;
    }

    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                for (int d = 1; d < len; d++) {
                    if (len % d == 0) {
                        cost[i][j] = min(cost[i][j], getchangeford(s, i, j, d));
                    }
                }
            }
        }
        // dp[groups][i] = min changes to split prefix s[0...i] into 'groups'
        // parts Indices: groups (1 to k), i (0 to n-1)
        vector<vector<int>> dp(k + 1, vector<int>(n, INT_MAX / 2));

        // Base case groups = 1
        for (int i = 0; i < n; i++) {
            /*
                the min changes required to split prefix s[0...i]
                into a single group would be the same as the cost
                of changes requried for s[0...i]
            */
            dp[1][i] = cost[0][i];
        }

        for (int groups = 2; groups <= k; groups++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    dp[groups][i] =
                        min(dp[groups][i], dp[groups - 1][j] + cost[j + 1][i]);
                }
            }
        }
        return dp[k][n - 1];
    }
};