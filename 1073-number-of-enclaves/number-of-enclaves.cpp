class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                grid[i][0]=-1;
                q.push({i,0});
            }
            if(grid[i][m-1]==1){
                grid[i][m-1]=-1;
                q.push({i, m-1});
            }
        }

        for(int i=1;i<m-1;i++){
            if(grid[0][i]==1){
                grid[0][i]=-1;
                q.push({0,i});
            }
            if(grid[n-1][i]==1){
                grid[n-1][i]=-1;
                q.push({n-1,i});
            }
        }
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};

        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int tempx = front.first+dx[i];
                int tempy = front.second+dy[i];

                if(tempx>=0 && tempx<n && tempy>=0 & tempy<m){
                    if(grid[tempx][tempy]==1){
                        grid[tempx][tempy]=-1;
                        q.push({tempx, tempy});
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};