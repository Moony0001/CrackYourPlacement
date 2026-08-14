class Solution {
public:
    int finddia(vector<vector<int>>& adj){
        int u = 0;

        int fnode = -1;

        vector<int> vis(adj.size(), 0);
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                int u = q.front();
                q.pop();
                fnode = u;
                for(int v : adj[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }

        int levels = 0;

        vis = vector<int> (adj.size(), 0);
        q.push(fnode);
        vis[fnode] = 1;

        while(!q.empty()){
            int n = q.size();
            levels++;
            for(int i=0;i<n;i++){
                int u = q.front();
                q.pop();
                for(int v : adj[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }

        return levels-1;
    }

    void makegraph(vector<vector<int>>& edges, vector<vector<int>>& adj){
        for(vector<int>& e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        makegraph(edges1, adj1);
        makegraph(edges2, adj2);

        int dia1 = finddia(adj1);
        int dia2 = finddia(adj2);

        int r1 = (dia1 + 1)/2;
        int r2 = (dia2 + 1)/2;

        int ans = r1 + r2 + 1;
        return max({ans, dia1, dia2});
    }
};