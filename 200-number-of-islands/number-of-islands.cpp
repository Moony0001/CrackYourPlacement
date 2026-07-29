class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) return;
        
        if(grid[x][y]=='1'){
            grid[x][y] = '-';
            dfs(grid, x+1, y);
            dfs(grid, x-1, y);
            dfs(grid, x, y-1);
            dfs(grid, x, y+1);
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
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};