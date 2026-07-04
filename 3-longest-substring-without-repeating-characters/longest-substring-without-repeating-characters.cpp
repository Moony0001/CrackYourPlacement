class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(256, -1);
        int i=0, j=0;
        int n = s.size();
        if(n==0) return 0;
        int ans = 0;
        while(j<n && i<=j){
            if(cnt[s[j]]==-1){
                cnt[s[j]] = j;
            }else{
                if(cnt[s[j]]>=i){
                    i = cnt[s[j]]+1;
                    cnt[s[j]] = j;
                }else{
                    cnt[s[j]] = j;
                }
                
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};