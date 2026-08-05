class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, vector<int>& remove, int curr){
        remove[curr] = 1;
        visited[curr] = 1;
        for(int &v : adj[curr]){
            if(remove[v]!=1){
                dfs(adj, visited, remove, v);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int>& v : edges){
            adj[v[0]].push_back(v[1]);
        }
        vector<int> remove(n, 0);
        vector<int> visited(n, 0);

        dfs(adj, visited, remove, k);
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[i] = i;
        }
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                for(int &v : adj[i]){
                    if(remove[v]==1){
                        return temp;
                    }
                }
                visited[i] = 1;
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(remove[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};