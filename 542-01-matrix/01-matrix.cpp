class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j] = -1;
                }
            }
        }
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();
            int val = mat[front.first][front.second];
            for(int i=0;i<4;i++){
                int tempx = front.first + dx[i];
                int tempy = front.second + dy[i];

                if(tempx>=0 && tempx<n && tempy>=0 && tempy<m){
                    if(mat[tempx][tempy]==-1){
                        mat[tempx][tempy] = val+1;
                        q.push({tempx, tempy});
                    }
                }
            }
        }
        return mat;
    }
};