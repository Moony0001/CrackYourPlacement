class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int t = n;
        while(t>0){
            rev = rev*10 + (t%10);
            t = t/10;
        }
        int ans = abs(n-rev);
        return ans;
    }
};