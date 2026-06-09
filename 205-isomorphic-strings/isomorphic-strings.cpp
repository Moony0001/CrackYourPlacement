class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        int n = s.size();
        bool flag1 = true;
        for(int i=0;i<n;i++){
            if(!mp.count(s[i])){
                mp[s[i]] = t[i];
            }else{
                if(mp[s[i]]!=t[i]){
                    flag1 = false;
                }
            }
        }
        unordered_map<char,char> mp2;
        bool flag2 = true;
        for(int i=0;i<n;i++){
            if(!mp2.count(t[i])){
                mp2[t[i]] = s[i];
            }else{
                if(mp2[t[i]]!=s[i]){
                    flag2 = false;
                }
            }
        }
        return (flag2&&flag1);
    }
};