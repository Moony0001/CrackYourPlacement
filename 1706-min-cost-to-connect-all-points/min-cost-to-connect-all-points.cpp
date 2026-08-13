class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = (abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]));
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n, 0);

        pq.push({0, 0});

        int ans = 0;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int w = p.first;
            int u = p.second;

            if(vis[u]) continue;

            vis[u] = 1;
            ans += w;

            for(pair<int,int> node : adj[u]){
                int v = node.first;
                int wt = node.second;

                if(!vis[v]){
                    pq.push({wt, v});
                }
            }
        }
        return ans;
    }
};