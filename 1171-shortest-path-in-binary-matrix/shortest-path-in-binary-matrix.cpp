class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size();
        if(n==1) return 1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        grid[0][0] = 1;
        vector<vector<int>> dir = {{0,1}, {1,0}, {1,1}, {-1, -1}, {1,-1}, {-1,1}, {0,-1}, {-1,0}};
        while(!pq.empty()){
            int w = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(w>dist[x][y]) continue;
            for(int i=0;i<8;i++){
                if(x+dir[i][0]>=0 && x+dir[i][0]<n && y+dir[i][1]>=0 && y+dir[i][1]<n && grid[x+dir[i][0]][y+dir[i][1]]==0 && (w+1 < dist[x+dir[i][0]][y+dir[i][1]])){
                    grid[x+dir[i][0]][y+dir[i][1]]=1;
                    dist[x+dir[i][0]][y+dir[i][1]] = w+1;
                    pq.push({w+1, {x+dir[i][0], y+dir[i][1]}});
                }
            }
        }
        return (dist[n-1][n-1]==INT_MAX) ? -1 : dist[n-1][n-1]+1;
    }
};