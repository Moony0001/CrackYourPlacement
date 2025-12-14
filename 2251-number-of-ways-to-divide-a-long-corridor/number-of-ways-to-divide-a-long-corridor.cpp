class Solution {
public:
    int m = 1000000007;
    int numberOfWays(string corridor) {
        vector<int> pos;
        int n = corridor.size();
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                pos.push_back(i);
            }
        }
        if(pos.size()==0 || pos.size()%2!=0) return 0;
        if(pos.size()==2) return 1;
        long long ans = 1;
        for(int i=1;i<pos.size()-1;i+=2){
            long long temp = pos[i+1]-pos[i];
            ans *= temp;
            ans = ans%m;
        }
        return (int)ans;
    }
};