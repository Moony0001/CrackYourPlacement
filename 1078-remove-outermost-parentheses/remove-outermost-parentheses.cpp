class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<int> st;
        vector<int> v;
        string ans = "";
        for(int i=0;i<n;i++){
            if(st.size() == 0){
               st.push(s[i]);
            }
            else{
                if(s[i] == ')' && st.size() == 1){
                    if(st.top() == '('){
                        st.pop();
                    }
                    continue;
                }
                else if(s[i] == '(') st.push(s[i]);
                else if(s[i] == ')') st.pop();
                ans += s[i];
            }
        }
        return ans;
    }
};