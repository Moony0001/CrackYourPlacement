class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> pos(26, -1);
        vector<bool> pres(26, false);
        for(int i=0;i<n;i++){
            pos[s[i]-'a'] = i;
        }
        stack<char> st;
        string ans = "";

        for(int i=0;i<n;i++){
                
            if(pres[s[i]-'a']){
                continue;
            }
            while(!st.empty() && s[i]<st.top() && pos[st.top()-'a']>i){
                pres[st.top()-'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            pres[s[i]-'a'] = true;
            
        }
        

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};