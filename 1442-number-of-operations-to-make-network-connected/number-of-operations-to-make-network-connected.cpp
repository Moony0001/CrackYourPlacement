class Solution {
public:
    int find(int i, vector<int>& parent){
        if(i==parent[i]) return i;

        return parent[i] = find(parent[i], parent);
    }

    void unionf(int u, int v, vector<int>& parent, vector<int>& rank){
        int u_parent = find(u, parent);
        int v_parent = find(v, parent);

        if(u_parent==v_parent) return;

        if(rank[u_parent] > rank[v_parent]){
            parent[v_parent] = u_parent;
        }else if(rank[u_parent] < rank[v_parent]){
            parent[u_parent] = v_parent;
        }else{
            parent[u_parent] = v_parent;
            rank[v_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int s = connections.size();
        if(s<(n-1)) return -1;

        vector<int> rank(n, 0);
        vector<int> parent (n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        int ans = n;
        for(int i=0;i<s;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(find(u, parent)!=find(v, parent)){
                unionf(u, v, parent, rank);
                ans--;
            }
        }

        return ans-1;
    }
};