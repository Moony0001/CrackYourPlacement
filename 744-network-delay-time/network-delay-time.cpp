class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(vector<int>& t : times){
            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({v, w});

        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;
        dist[0] = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            for(pair<int,int>& p : adj[u]){
                int v = p.first;
                int wt = p.second;

                if(w+wt < dist[v]){
                    dist[v] = w+wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for(int& i : dist){
            if(i==INT_MAX){
                return -1;
            }
            ans = max(ans, i);
        }
        return ans;
        
    }
};