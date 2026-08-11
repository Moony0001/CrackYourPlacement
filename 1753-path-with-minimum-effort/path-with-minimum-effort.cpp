class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!pq.empty()){
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();
            if(x==n-1 && y==m-1) return diff;

            if(diff > dist[x][y]) continue;
            for(int i=0;i<4;i++){
                int x_new = x+dir[i][0];
                int y_new = y+dir[i][1];
                

                if(x_new>=0 && x_new<n && y_new>=0 && y_new<m){
                    int diff_new = abs(heights[x][y] - heights[x_new][y_new]);
                    int max_diff = max(diff, diff_new);
                    if(dist[x_new][y_new] > max_diff){
                        dist[x_new][y_new] = max_diff;
                        pq.push({max_diff, {x_new, y_new}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};