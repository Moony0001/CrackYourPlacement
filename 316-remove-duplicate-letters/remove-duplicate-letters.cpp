class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> pos (26, -1);
        for(int i=0;i<n;i++){
            pos[s[i]-'a'] = i;
        }

        vector<bool> pres (26, false);
        stack<char> st;
        for(int i=0;i<n; i++){
            if(pres[s[i]-'a']) continue;

            while(!st.empty() && s[i]<st.top() && pos[st.top()-'a']>i){
                pres[st.top()-'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            pres[s[i]-'a'] = true;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};