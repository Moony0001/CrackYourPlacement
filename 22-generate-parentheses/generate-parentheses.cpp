class Solution {
public:

    void genpar(vector<string>& ans, string& s, int n, int counto, int countc){
        if(counto==n && countc==n){
            ans.push_back(s);
            return;
        }
        if(counto<n){
            s+='(';
            genpar(ans, s, n, counto+1, countc);
            s.pop_back();
        }
        if(counto>countc){
            s+=')';
            genpar(ans, s, n, counto, countc+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        genpar(ans, s, n, 0, 0);
        return ans;
    }
};