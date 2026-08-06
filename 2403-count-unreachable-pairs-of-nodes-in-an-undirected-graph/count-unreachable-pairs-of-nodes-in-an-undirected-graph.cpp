class Solution {
public:
    int find(int i, vector<int>& parent){
        if(i==parent[i]) return i;

        return parent[i] = find(parent[i], parent);
    }

    void unionf(int u, int v, vector<int>& parent, vector<int>& rank){
        int u_parent = find(u, parent);
        int v_parent = find(v, parent);

        if(u_parent==v_parent) return;
        if(rank[u_parent] > rank[v_parent]){
            parent[v_parent] = u_parent;
        }else if(rank[v_parent] > rank[u_parent]){
            parent[u_parent] = v_parent;
        }else{
            parent[u_parent] = v_parent;
            rank[v_parent]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<int> rank(n, 0);
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(vector<int>& e : edges){
            int u = e[0];
            int v = e[1];
            if(find(u, parent) != find(v, parent)){
                unionf(u, v, parent, rank);
            }
        }

        unordered_map<long long,long long> mp;
        for(int i=0;i<n;i++){
            mp[find(i, parent)]++;
        }

        for(auto&m : mp){
            ans += (m.second)*(n-m.second);
        }
        return ans>>1;
    }
};