class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_set<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(!mp.count(s[i])){
                if(!st.count(t[i])){
                    mp[s[i]] = t[i];
                    st.insert(t[i]);
                }else{
                    return false;
                }
            }else{
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        
        return true;
    }
};