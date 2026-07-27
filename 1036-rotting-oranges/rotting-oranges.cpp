class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j] = 1;
                }else if(grid[i][j]==1){
                    cnt++;
                }else{
                    vis[i][j] = 1;
                }
            }
        }
        int ans = 0;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        while(!q.empty()){
            int s = q.size();
            ans++;
            for(int i=0;i<s;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int tempx = x+dx[j];
                    int tempy = y+dy[j];
                    if(tempx>=0 && tempx<n && tempy>=0 && tempy<m){
                        if(!vis[tempx][tempy]){
                            q.push({tempx, tempy});
                            vis[tempx][tempy] = 1;
                            cnt--;
                        }
                    }
                }
            }
        }
        if(cnt>0) return -1;
        return ans > 0 ? ans-1: 0;
    }
};