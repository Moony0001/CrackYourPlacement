class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis,  int curr) {
        vis[curr] = 1;
        bool ans = true;
        pathvis[curr] = 1;
        for (int i : adj[curr]) {
            if (pathvis[i]) {
                return false;
            } else if(!vis[i]){
                ans = dfs(adj, vis, pathvis, i);
                if(!ans) return ans;
            }
        }
        pathvis[curr] = 0;
        return ans;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);

        for (vector<int>& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }
        vector<int> vis(n, 0);
        vector<int> pathvis (n, 0);
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && adj[i].size()>0) {
                ans = dfs(adj, vis, pathvis, i);
                if(!ans) return ans;
            }
        }
        return ans;
    }
};