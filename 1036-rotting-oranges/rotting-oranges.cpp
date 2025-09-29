class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fo = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fo++;
                }
            }
        }
        int time = 0;

        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        while(fo!=0 && !q.empty()){
            int qs = q.size();
            for(int i=0;i<qs;i++){
                int ri = q.front().first;
                int rj = q.front().second;
                q.pop();
                for(auto d: dirs){
                    int newX = ri+d.first;
                    int newY = rj+d.second;
                    if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1){
                        grid[newX][newY] = 2;
                        fo--;
                        q.push({newX,newY});
                    }
                }
            }
            time++;
        }
        return fo==0 ? time : -1;
    }
};