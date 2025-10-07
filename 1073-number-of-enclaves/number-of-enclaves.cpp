class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count1 = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis (m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count1++;
                    if(i==0 || i==m-1 || j==0 || j==n-1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            count1--;
            vis[x.first][x.second]=1;
            vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
            for(auto d : dir){
                int newx = x.first+d.first;
                int newy = x.second+d.second;
                if(newx>=0 && newx<m && newy>=0 && newy<n){
                    if(!vis[newx][newy] && grid[newx][newy]){
                        vis[newx][newy]=1;
                        q.push({newx,newy});
                    }
                }
            }
        }
        return (count1<0?0:count1);
    }
};