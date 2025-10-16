class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> adj(n, 0);
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]-1]++;
            adj[edges[i][1]-1]++;
        }
        int maxi = INT_MIN;
        int ind = -1;
        for(int i=0;i<n;i++){
            if(maxi<adj[i]){
                maxi = adj[i];
                ind = i;
            }
        }
        return ind+1;
    }
};