class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string s1 = "";
        string s2 = "";
        int t = n;
        while(t>0){
            if(t&1){
                s1.push_back('1');
                s2.push_back('0');
            }else{
                s1.push_back('0');
                s2.push_back('1');
            }
            t--;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<n;i++){
            if(s[i]!=s1[i]){
                cnt1++;
            }
            if(s[i]!=s2[i]){
                cnt2++;
            }
        }
        int ans = min(cnt1, cnt2);
        return ans;
    }
};