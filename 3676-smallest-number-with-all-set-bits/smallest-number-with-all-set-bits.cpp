class Solution {
public:
    int smallestNumber(int n) {
        int t = n;
        int cnt = 0;
        while(t>0){
            t=t>>1;
            cnt++;
        }
        int ans = (int)pow(2,cnt);
        ans--;
        return ans;
    }
};