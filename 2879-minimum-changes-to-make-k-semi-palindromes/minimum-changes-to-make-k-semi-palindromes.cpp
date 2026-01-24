class Solution {
public:
    /*
    This function checks the substring of s at the bounds of left and right with a jump
    of d. We use two pointers, p1 and p2, send p2 to the back of the substring and
    then use these two pointers to check how many changes are required to make the 
    substring a semi palindrome by counting how many times there is a mismatch while
    checking whether the substring is a palindrome or not
    */

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
        /*
        In the following code block we calculate the cost/no. of letters to be
        changed to make the string s[i...j] a semi-palindrome. To do that we will
        use two pointers and calculate the length using this and then take the
        divisors of this len and use the function above to calculate the num of
        changes required to make it a semi palindrome.
        */
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
        /*
        We calculated the base case of groups = 1 above, now for groups = 2 till 
        k (that we want), we use DP.
        To do this, we use the bottom-up approach i.e. start small go big.
        For each group size, for each length of string from 0 to n, we try
        every index j<i as the end of the last group and take j+1 to i as the next 
        group.        
        */
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