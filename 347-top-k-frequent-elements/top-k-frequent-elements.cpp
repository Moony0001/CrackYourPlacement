class Solution {
public:
    struct CompareMap{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b){
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, CompareMap> pq;
        for(auto& m : mp){
            if(pq.size()<k){
                pq.push({m.second, m.first});
            }else{
                auto top = pq.top();
                if(top.first<m.second){
                    pq.pop();
                    pq.push({m.second, m.first});
                }
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};