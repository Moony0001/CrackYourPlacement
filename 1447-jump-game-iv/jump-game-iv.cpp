class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        queue<vector<int>> q;
        q.push({0});
        int ans = 0;
        vector<int> vis(n,0);
        vis[0]=1;
        unordered_set<int> st;
        while(!q.empty()){
            vector<int> temp;
            vector<int> trav = q.front();
            q.pop();
            for(int i=0;i<trav.size();i++){
                if(trav[i]==n-1){
                    return ans;
                }

                if(trav[i]-1>=0 && !vis[trav[i]-1]){
                    vis[trav[i]-1] = 1;
                    temp.push_back(trav[i]-1);
                }
                if(trav[i]+1<n && !vis[trav[i]+1]){
                    vis[trav[i]+1] = 1;
                    temp.push_back(trav[i]+1);
                }

                if(!st.count(arr[trav[i]])){
                    st.insert(arr[trav[i]]);
                    for(int j=0;j<mp[arr[trav[i]]].size();j++){
                        if(!vis[mp[arr[trav[i]]][j]]){
                            temp.push_back(mp[arr[trav[i]]][j]);
                            vis[mp[arr[trav[i]]][j]] = 1;
                        }
                    
                    }
                }
                
            }
            if(temp.size()>0){
                q.push(temp);
                ans++;
            }
        }
        return ans;
    }
};