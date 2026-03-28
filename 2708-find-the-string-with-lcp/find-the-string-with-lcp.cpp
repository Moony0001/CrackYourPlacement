class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        char curr = 'a';
        string s(n,'.');
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                if(curr>'z'){
                    return "";
                }
                s[i]=curr;
                int j=i+1;
                while(j<n){
                    if(lcp[i][j]>0){
                        s[j]=curr;
                    }
                    j++;
                }
                curr++;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s[i]==s[j]){
                    if(i==n-1 || j==n-1){
                        if(lcp[i][j] != 1){
                            return "";
                        }
                    }else{
                        if(lcp[i][j]!=lcp[i+1][j+1]+1){
                            return "";
                        }
                    }
                }else{
                    if(lcp[i][j]!=0){
                        return "";
                    }
                }
            }
        }

        return s;
    }
};