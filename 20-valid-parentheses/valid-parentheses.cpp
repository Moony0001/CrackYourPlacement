class Solution {
public:
    bool isValid(string s) {
        if(s.size()&1) return false;
        stack<char> st;
        for(char c : s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }else{
                if(!st.empty()){
                    if(c==')'){
                        if(st.top()!='('){
                            return false;
                        }
                    }else if(c=='}'){
                        if(st.top()!='{'){
                            return false;
                        }
                    }else if(c==']'){
                        if(st.top()!='['){
                            return false;
                        }
                    }
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};