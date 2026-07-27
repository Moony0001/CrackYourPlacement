class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                ans ++;
                while(!q.empty()){
                    int f = q.front();
                    q.pop();
                    for(int j : adj[f]){
                        if(!vis[j]){
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;

    }
};