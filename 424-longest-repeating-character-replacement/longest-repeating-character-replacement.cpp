class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26,0);
        int maxi = 0;
        int i=0;
        int ans = 0;
        int n = s.size();
        for(int j=0;j<n;j++){
            cnt[s[j]-'A']++;
            if(cnt[s[j]-'A']>maxi){
                maxi = cnt[s[j]-'A'];
            }
            int len = j-i+1;
            int rem = len-maxi;
            if(rem>k){
                cnt[s[i]-'A']--;
                i++;
            }

            ans = max(ans, j-i+1);
        }
        return ans;
    }
};