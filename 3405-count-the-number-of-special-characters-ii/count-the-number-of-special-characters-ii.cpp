class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> upper(26,-1);
        vector<int> lower(26,-1);
        vector<int> mark(26,0);
        int ans = 0;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(c>=65 && c<=90){
                if(!mark[c-'A']){
                    upper[c-'A'] = i;
                    mark[c-'A'] = 1;
                }
            }
            if(c>=97 && c<=122){
                lower[c-'a'] = i;
            }
        }

        for(int i=0;i<26;i++){
            if(upper[i]>-1 && lower[i]>-1){
                if(upper[i]>lower[i]){
                    ans++;
                }
            }
        }       
        return ans;
    }
};