class Solution {
public:
    bool bobdfs(vector<vector<int>> &adj,vector<int> &bt, int time, int curr, int parent){
        if(curr == 0){
            bt[0] = time;
            return true;
        }

        for(int v : adj[curr]){
            if(v!=parent){
                if(bobdfs(adj, bt, time+1, v, curr)){
                    bt[curr] = time;
                    return true;
                }

            }
        }
        return false;
    }

    int alicedfs(vector<vector<int>> &adj, vector<int>&bt, vector<int> &amount, int time, int curr, int parent){
        int maxi = INT_MIN;
        int temp = 0;

        if(time<bt[curr]){
            temp = amount[curr];
        }else if(time==bt[curr]){
            temp = (amount[curr]/2);
        }

        for(int v : adj[curr]){
            if(v!=parent){
                int total = alicedfs(adj, bt, amount, time+1, v, curr);
                maxi = max(maxi, total);
            }
        }
        if(maxi==INT_MIN) return temp;
        return maxi+temp;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        vector<vector<int>> adj (n+1);

        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //vector that contains the times when bob reached a node
        vector<int> bt(n+1, INT_MAX);
        bobdfs(adj, bt, 0, bob, -1);

        int ans = alicedfs(adj, bt, amount, 0, 0, -1);
        return ans;
    }
};