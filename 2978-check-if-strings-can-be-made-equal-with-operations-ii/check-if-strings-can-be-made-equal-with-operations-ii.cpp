class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<int, int> mp1, mp2;
        int n = s1.size();
        for(int i=0;i<n;i++){
            if(i&1){
                mp2[s1[i]]++;
            }else{
                mp1[s1[i]]++;
            }
        }

        for(int i=0;i<n;i++){
            if(i&1){
                if(mp2[s2[i]]==0){
                    return false;
                }else{
                    mp2[s2[i]]--;
                }
            }else{
                if(mp1[s2[i]]==0){
                    return false;
                }else{
                    mp1[s2[i]]--;
                }
            }
        }
        return true;
    }
};