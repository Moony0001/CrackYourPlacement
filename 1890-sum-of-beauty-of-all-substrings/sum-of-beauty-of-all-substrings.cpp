class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int cnt[26] = {0};
            for(int j=i;j<n;j++){
                cnt[s[j]-'a']++;
                int maxi = 0;
                int mini = INT_MAX;
                for(int c : cnt){
                    if(c>0){
                        maxi = max(c, maxi);
                        mini = min(c, mini);
                    }
                }
                ans += (maxi-mini);
            }
        }
        return ans;
    }
};