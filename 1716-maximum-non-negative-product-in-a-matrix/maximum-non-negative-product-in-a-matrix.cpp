class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> maxgt(m, vector<long long>(n,INT_MAX));
        vector<vector<long long>> mingt(m, vector<long long>(n,INT_MIN));
        maxgt[0][0] = grid[0][0];
        mingt[0][0] = grid[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }

                if(grid[i][j]>=0){
                    if(i==0){
                        maxgt[i][j] = maxgt[i][j-1] * grid[i][j];
                        mingt[i][j] = mingt[i][j-1] * grid[i][j];
                    }else if(j==0){
                        maxgt[i][j] = maxgt[i-1][j] * grid[i][j];
                        mingt[i][j] = mingt[i-1][j] * grid[i][j];
                    }else{
                        maxgt[i][j] = max(maxgt[i-1][j], maxgt[i][j-1]) * grid[i][j];
                        mingt[i][j] = min(mingt[i-1][j], mingt[i][j-1]) * grid[i][j];
                    }
                }else{
                    if(i==0){
                        maxgt[i][j] = mingt[i][j-1] * grid[i][j];
                        mingt[i][j] = maxgt[i][j-1] * grid[i][j];
                    }else if(j==0){
                        maxgt[i][j] = mingt[i-1][j] * grid[i][j];
                        mingt[i][j] = maxgt[i-1][j] * grid[i][j];
                    }else{
                        maxgt[i][j] = min(mingt[i-1][j], mingt[i][j-1]) * grid[i][j];
                        mingt[i][j] = max(maxgt[i-1][j], maxgt[i][j-1]) * grid[i][j];
                    }
                    
                }
            }
        }

        if(maxgt[m-1][n-1]<0){
            return -1;
        }
        return maxgt[m-1][n-1]%1000000007;
    }
};