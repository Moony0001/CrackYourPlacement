class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int og = image[sr][sc];
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({sr,sc});
        vis[sr][sc] = 1;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                image[x][y] = color;
                for(int j=0;j<4;j++){
                    int tempx = x + dx[j];
                    int tempy = y + dy[j];
                    if(tempx>=0 && tempx<n && tempy>=0 && tempy<m){
                        if(!vis[tempx][tempy]){
                            if(image[tempx][tempy]==og){
                                q.push({tempx, tempy});
                            }
                            vis[tempx][tempy] = 1;
                        }
                    }
                }
            }
        }
        return image;
    }
};