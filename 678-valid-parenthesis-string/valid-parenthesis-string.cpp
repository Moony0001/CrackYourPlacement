class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star;
        stack<int> open;
        for(int i =0;i<s.size();i++){
            char c = s[i];
            if(c=='('){
                open.push(i);
            }else if(c==')'){
                if(!open.empty()){
                    open.pop();
                }else if(!star.empty()){
                    star.pop();
                }else{
                    return false;
                }
            }else{
                star.push(i);
            }   
        }

        while(!open.empty()){
            if(star.empty()) return false;
            if(open.top()<star.top()){
                open.pop();
                star.pop();
            }else{
                return false;
            }
        }
        return true;
    }
};