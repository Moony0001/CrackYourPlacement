class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n,1);
        vector<int> v;
        queue<int> qc;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            if(rains[i]>0){
                qc.push(rains[i]);
                if(!mp.count(rains[i])){
                    ans[i]=-1;
                    mp[rains[i]]=i;
                }else{
                    int k = mp[rains[i]];
                    auto it = upper_bound(v.begin(), v.end(), k);
                    if(it!=v.end()){
                        int ind = 0;
                        ind = *it;
                        if(ind<i){
                            ans[ind]=rains[i];
                            ans[i]=-1;
                            mp[rains[i]]=i;
                            v.erase(it);
                        }else{
                            vector<int> a;
                            return a;
                        }
                    }else{
                        vector<int> a;
                        return a;
                    }
                }
                
            }else if(rains[i]==0){
                if(!qc.empty()){
                    v.push_back(i);
                }
            }
        }
        for(int i=0;i<v.size();i++){
            ans[v[i]] = 1;
        }
        
        return ans;
    }
};