class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(char c : s){
            if(c>='a' && c <= 'z'){
                result+=c;
            }else if(c=='*'){
                if(result.size()>0){
                    result.pop_back();
                }
            }else if(c=='#'){
                result += result;
            }else{
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};