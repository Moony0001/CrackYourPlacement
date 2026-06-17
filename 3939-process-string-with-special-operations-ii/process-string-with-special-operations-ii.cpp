class Solution {
public:
    char processStr(string s, long long k) {
        long long cnt = 0;
        int n = s.size();
        vector<long long> l (n,0);
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c>='a' && c<='z'){
                cnt++;
            }else if(c=='*'){
                cnt = max(0LL, cnt-1);
            }else if(c=='#'){
                cnt += cnt;
            }
            l[i] = cnt;
        }

        if(l[n-1]==0 || k>=l[n-1]) return '.';

        long long target = k;

        for(int i=n-1;i>=0;i--){
            if(s[i]>='a' && s[i]<='z'){
                if(target==(l[i]-1)){
                    return s[i];
                }
            }else if(s[i]=='#'){
                if(i>0){
                    if(l[i-1]>0){
                        target = target%l[i-1];
                    }
                }
            }else if(s[i]=='%'){
                target = l[i]-target-1;
            }
        }

        return '.';

    }
};