class Solution {
public:
    string largestOddNumber(string num) {
        int ind = -1;
        int n = num.size();
        for(int i=n-1;i>=0;i--){
            char c = num[i];
            if((c-'0')&1){
                ind = i;
                break;
            }
        }
        if(ind==-1){
            return "";
        }
        string ans = num.substr(0,ind+1);
        return ans;
    }
};