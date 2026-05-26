class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> upper(26,0);
        vector<int> lower(26,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(word[i]>=65 && word[i]<=90){
                upper[word[i]-'A']=1;
            }
            if(word[i]>=97 && word[i]<=122){
                lower[word[i]-'a']=1;
            }
        }

        for(int i=0;i<26;i++){
            if(upper[i] && lower[i]){
                ans++;
            }
        }
        return ans;
    }   
};