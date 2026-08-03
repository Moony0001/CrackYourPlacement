class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& color, int curr, int currcolor){
        color[curr] = currcolor;

        for(int &v : adj[curr]){
            if(color[v]==currcolor) return false;
            if(color[v] == -1){
                if(dfs(adj, color, v, 1-currcolor)==false){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color (n, -1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(graph, color, i, 0)== false) return false;
            }
        }

        return true;
    }
};