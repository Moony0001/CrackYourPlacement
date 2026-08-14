class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //1. Build a graph using adjacency map
        
        int n = pairs.size();
        unordered_map<int, vector<int>> adj;

        unordered_map<int, int> indegree;
        unordered_map<int, int> outdegree;

        for(vector<int>& p : pairs){
            adj[p[0]].push_back(p[1]);
            outdegree[p[0]]++;
            indegree[p[1]]++;
        }

        //Find the start node of the Euler path

        int start = pairs[0][0];
        for(auto& it : adj){
            int i = it.first;
            if(outdegree[i]-indegree[i]==1){
                start = i;
                break;
            }
        }

        //Perform the DFS

        vector<int> path;
        stack<int> st;  // To perform DFS

        st.push(start);
        
        while(!st.empty()){
            int curr = st.top();

            if(!adj[curr].empty()){
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }else{
                path.push_back(curr);
                st.pop();
            }
        }

        // Build your result

        reverse(path.begin(), path.end());

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            ans.push_back({path[i], path[i+1]});
        }
        return ans;
    }
};