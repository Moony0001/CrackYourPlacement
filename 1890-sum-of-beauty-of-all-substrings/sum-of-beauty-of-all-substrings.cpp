class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int> cnt (26,0);
            unordered_set<char> st;
            for(int j=i;j<n;j++){
                st.insert(s[j]);
                cnt[s[j]-'a']++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(char c : st){
                    maxi = max(cnt[c-'a'], maxi);
                    mini = min(cnt[c-'a'], mini);
                }
                ans += (maxi-mini);
            }
        }
        return ans;
    }
};