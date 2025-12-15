class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long n = prices.size();
        long long i = 0, j = 1;
        while (j < n && i <= j) {
            if (prices[j-1] - prices[j] == 1) {
                j++;
            } else {
                long long p = j - i;
                long long temp = p * (p + 1) / 2;
                ans += temp;
                i = j;
                j++;
            }
        }
        long long pt = j - i;
        long long tempt = pt * (pt + 1) / 2;
        ans += tempt;
        return ans;
    }
};