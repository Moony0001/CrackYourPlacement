class Solution {
public:
    long long countCommas(long long n) {
        long long x1 = (n - 999) < 0 ? 0 : (n - 999);
        long long x2 = (n - 999999) < 0 ? 0 : (n - 999999);
        long long x3 = (n - 999999999) < 0 ? 0 : (n - 999999999);
        long long x4 = (n - 999999999999) < 0 ? 0 : (n - 999999999999);
        long long x5 = (n - 999999999999999) < 0 ? 0 : (n - 999999999999999);

        return (x1 + x2 + x3 + x4 + x5);
    }
};