class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int cnt1 = 0;
        int i = 0;
        while(i<n){
            if(s[i]=='1'){
                int j = i;
                while(j<n && s[j]=='1'){
                    j++;
                }
                i = j-1;
                cnt1++;
            }
            i++;
        }
        if(cnt1==1){
            return true;
        }
        return false;
    }
};