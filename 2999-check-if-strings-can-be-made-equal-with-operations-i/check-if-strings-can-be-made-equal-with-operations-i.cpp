class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<int, int> st1, st2;
        st1[s1[0]]++; st2[s1[1]]++; st1[s1[2]]++; st2[s1[3]]++;
        for(int i=0;i<4;i++){
            if(i&1){
                if(!st2.count(s2[i]) || st2[s2[i]]==0){
                    return false;
                }else{
                    st2[s2[i]]--;
                }
            }else{
                if(!st1.count(s2[i]) || st1[s2[i]]==0){
                    return false;
                }else{
                    st1[s2[i]]--;
                }
            }
        }
        return true;
    }
};