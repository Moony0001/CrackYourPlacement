class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        if(n==1) return 1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int level = 0;
        vector<int> dx = {0, 1, 1, 0, -1, 1, -1, -1};
        vector<int> dy = {1, 0, 1, -1, 0, -1, 1, -1};
        while(!q.empty()){
            int m = q.size();
            level++;
            for(int i=0;i<m;i++){
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for(int i=0;i<8;i++){
                    if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n && grid[x+dx[i]][y+dy[i]]==0){
                        if(x+dx[i]==n-1 && y+dy[i]==n-1) return level+1;
                        q.push({(x+dx[i]),(y+dy[i])});
                        grid[x+dx[i]][y+dy[i]]=1;
                    }
                }
            }
        }
        return -1;
    }
};