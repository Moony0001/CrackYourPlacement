class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt (26, 0);
        for(char c : s){
            cnt[c-'a']++;
        }
        int n = s.size();
        string ans(n, '#');
        int i=0, j=n-1;
        for(int k=0;k<26;k++){
            while(cnt[k]>0){
                if(cnt[k]>1){
                    ans[i] = k+'a';
                    ans[j] = k+'a';
                    i++; j--;
                    cnt[k]-=2;
                }else{
                    int mid = i + (j-i)/2;
                    ans[mid] = k+'a';
                    cnt[k]--;
                }
            }
        }
        return ans;
    }
};