class Solution {
public:
    void bfs(vector<vector<char>>& grid, int x, int y){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({x,y});
        grid[x][y] = '-';
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int tempx = p.first+dx[i];
                int tempy = p.second+dy[i];

                if(tempx>=0 && tempx<n && tempy>=0 && tempy<m){
                    if(grid[tempx][tempy]=='1'){
                        grid[tempx][tempy] = '-';
                        q.push({tempx, tempy});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};