class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int cnt = 0;
        int temp = n;
        while(temp>0){
            temp = temp>>1;
            cnt++;
        }
        long long pw = 1;
        while(cnt>0){
            pw = pw<<1;
            cnt--;
        }
        int ans = pw-n-1;
        return ans;
    }
};