class Solution {
public:
    bool help(string& a, string& b){
        int cnt = 0;
        int n = a.size();
        int m = b.size();
        if(n+1!=m) return false;
        int i=0, j=0;
        while(i<n && j<m){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                cnt++;
                j++;
            }
        }
        return (cnt<=1);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        int ans = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(help(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j]+1);
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};