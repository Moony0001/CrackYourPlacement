class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> rowpref(n, 0);
        vector<long long> colpref(m, 0);

        for(int i=0;i<n;i++){
            long long row = 0;
            for(int j=0;j<m;j++){
                row+=grid[i][j];
            }
            rowpref[i]=row;
        }

        for(int i=0;i<m;i++){
            long long col = 0;
            for(int j=0;j<n;j++){
                col+=grid[j][i];
            }
            colpref[i] = col;
        }

        vector<long long> rowrowpref(n,0);
        vector<long long> colcolpref(m,0);

        long long row = 0;
        for(int i=0;i<n;i++){
            row+=rowpref[i];
            rowrowpref[i] = row;
        }
        long long col = 0;
        for(int i=0;i<m;i++){
            col+=colpref[i];
            colcolpref[i] = col;
        }

        for(int i=0;i<n-1;i++){
            if(rowrowpref[i]==(row-rowrowpref[i])){
                return true;
            }
        }

        for(int j=0;j<m-1;j++){
            if(colcolpref[j]==(col-colcolpref[j])){
                return true;
            }
        }
        return false;
    }
};