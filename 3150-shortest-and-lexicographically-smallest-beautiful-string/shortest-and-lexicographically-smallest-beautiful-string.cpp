class Solution {
public:
    string lexsmall(string a, string b){
        if(a.size() < b.size()){
            return a;
        }else if(a.size() > b.size()){
            return b;
        }

        for(int i=0;i<a.size();i++){
            if(a[i] < b[i]){
                return a;
            }else if(a[i] > b[i]){
                return b;
            }
        }
        return a;
    }

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<int> pre(n+1, 0);
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c=='1'){
                pre[i+1] = pre[i]+1;
            }else{
                pre[i+1] = pre[i];
            }
        }
        int i=0, j=0;
        string ans = "";
        while(j<n){
            if(pre[j+1]-pre[i] >= k){
                while(i<=j && pre[j+1]-pre[i+1]>=k){
                    i++;
                }
                if(ans==""){
                    ans = s.substr(i, (j-i+1));
                }else{
                    string temp = s.substr(i, (j-i+1));
                    ans = lexsmall(ans, temp);
                }
                j++;
            }else if(pre[j+1]-pre[i] < k){
                j++;
            }
        }
        return ans;
    }
};