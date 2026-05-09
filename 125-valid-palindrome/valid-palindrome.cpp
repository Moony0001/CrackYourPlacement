class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for(int i=0;i<s.size();i++){
            if((s[i]>=48 && s[i]<=57) || (s[i]>=97 && s[i]<=122)){
                s1.push_back(s[i]);
            }else if(s[i]>=65 && s[i]<=90){
                s1.push_back(s[i]+32);
            }
        }
        int a = 0, b = s1.size()-1;
        while(a<b){
            if(s1[a]!=s1[b]){
                return false;
            }
            a++; b--;
        }
        return true;
    }
};