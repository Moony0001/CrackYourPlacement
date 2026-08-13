class Solution {
public:
    int find(int i, vector<int>& parent){
        if(i==parent[i]){
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }

    void unionf(int u, int v, vector<int>& parent, vector<int>& rank){
        int u_parent = find(u, parent);
        int v_parent = find(v, parent);

        if(u_parent != v_parent){
            if(rank[u_parent] > rank[v_parent]){
                parent[v_parent] = u_parent;
            }else if(rank[u_parent] < rank[v_parent]){
                parent[u_parent] = v_parent;
            }else{
                parent[u_parent] = v_parent;
                rank[v_parent]++;
            }
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = (abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]));
                edges.push_back({dist, i, j});
            }
        }

        vector<int> parent(n, -1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        vector<int> rank(n, 0);

        sort(edges.begin(), edges.end());
        int ans = 0;
        for(int i=0;i<edges.size();i++){
            int w = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if(find(u, parent) != find(v, parent)){
                ans+= w;
                unionf(u, v, parent, rank);
            }
        }
        return ans;
    }
};