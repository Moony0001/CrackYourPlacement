class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> st;
        int n = num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && num[st.back()]>num[i]){
                st.pop_back();
                k--;
            }
            st.push_back(i);
        }
        while(k>0){
            st.pop_back();
            k--;
        }
        if(st.size()==0) return "0";
        string ans = "";
        int flag = 0;
        for(int i=0;i<st.size();i++){
            if(flag==0 && num[st[i]]=='0'){
                if(!ans.empty()){
                    ans.pop_back();
                    ans += num[st[i]];
                }else{
                    ans += num[st[i]];
                }
            }else if(flag==0 && num[st[i]]!='0'){
                while(!ans.empty()){
                    ans.pop_back();
                }
                flag = 1;
                ans += num[st[i]];
            }else if(flag==1){
                ans += num[st[i]];
            }
        }
        return ans;
    }
};