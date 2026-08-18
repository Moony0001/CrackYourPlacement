class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        // vector<int> dp(n+1, 0);
        int first = 0;
        int second = 1;
        for(int i=2;i<=n;i++){
            int val = first + second;
            first = second;
            second = val;
        }
        return second;
    }
};