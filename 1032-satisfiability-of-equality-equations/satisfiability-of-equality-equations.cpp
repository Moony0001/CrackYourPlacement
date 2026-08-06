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
        if(rank[u_parent]>rank[v_parent]){
            parent[v_parent] = u_parent;
        }else if(rank[u_parent]<rank[v_parent]){
            parent[u_parent] = v_parent;
        }else{
            parent[u_parent] = v_parent;
            rank[v_parent]++;
        }
    }

    bool equationsPossible(vector<string>& nums) {
        vector<int> rank(26, 0);
        vector<int> parent(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
        int n = nums.size();
        for(int i=0;i<n;i++){
            int u = nums[i][0]-'a';
            int v = nums[i][3]-'a';
            if(nums[i][1]=='='){
                unionf(u,v,parent, rank);
            }
        }
        for(int i=0;i<n;i++){
            int u = nums[i][0]-'a';
            int v = nums[i][3]-'a';
            if(nums[i][1]=='!'){
                if(find(u, parent)==find(v,parent)){
                    return false;
                }
            }
        }
        return true;
    }
};