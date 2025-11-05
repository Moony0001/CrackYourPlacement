class Solution {
public:
    map<long long, long long> freq;
    multiset<pair<int,int>> tx;
    multiset<pair<int,int>, greater<pair<int,int>>> ot;
    long long curr = 0;
    int lim = 0;

    void add(pair<int,int> p){
        if(p.first==0){
            return;
        }
        tx.insert(p);
        curr += (long long)p.first*p.second;

        if(tx.size()>lim){
            auto sm = *tx.begin();
            curr -= (long long)sm.first*sm.second;
            ot.insert(sm);
            tx.erase(tx.begin());
        }
    }

    void remove(pair<int,int> p){
        if(p.first==0) return;

        auto it = tx.find(p);
        if(it!=tx.end()){
            tx.erase(it);
            curr-=(long long)p.first*p.second;
            if(!ot.empty()){
                auto lg = *ot.begin();
                curr+=(long long)lg.first*lg.second;
                tx.insert(lg);
                ot.erase(ot.begin());

            }
        }else{
            auto ito = ot.find(p);
            if(ito!=ot.end()){
                ot.erase(ito);
            }
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> ans;
        int n = nums.size();
        
        lim = x;

        for(int i=0;i<k;i++){
            freq[nums[i]]++;
        }

        for(auto const& [val, fq]: freq){
            add({fq, val});
        }
        ans.push_back(curr);
        for(int r=k;r<n;++r){
            int l = r-k;

            int lev = nums[l];
            int ent = nums[r];

            if (lev==ent){
                ans.push_back(curr);
                continue;
            }

            int oldfl = freq[lev];
            int oldfr = freq[ent];
            int newfl = oldfl-1;
            int newfr = oldfr+1;

            remove({oldfl, lev});
            add({newfl, lev});
            freq[lev]--;

            remove({oldfr, ent});
            add({newfr, ent});
            freq[ent]++;
            ans.push_back(curr);
        }
        return ans;
    }   
};