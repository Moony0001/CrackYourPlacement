class Solution {
public:
    bool bfs(vector<vector<int>>& adj, vector<int>& color, int curr, int col){
        queue<int> q;
        q.push(curr);
        color[curr] = col;
        while(!q.empty()){
            int m = q.size();
            for(int i=0;i<m;i++){
                int curr = q.front();
                q.pop();
                for(int &v : adj[curr]){
                    if(color[v] == col) return false;
                    if(color[v]==-1){
                        color[v] = 1-col;
                        q.push(v);
                    }
                }
            }
            col = 1-col;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(graph, color, i, 0)==false) return false;
            }
        }
        return true;
    }
};