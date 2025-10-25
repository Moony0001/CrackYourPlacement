class Solution {
public:
    bool check(int x){
        vector<int> st(10,0);
        int t = x;
        while(t>0){
            int l = t%10;
            st[l]++;
            t/=10;
        }
        for(int i=0;i<10;i++){
            if(st[i]!=0){
                if(st[i]!=i){
                    return false;
                }
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int s = n+1;
        while(!check(s)){
            s++;
        }
        return s;
    }
};