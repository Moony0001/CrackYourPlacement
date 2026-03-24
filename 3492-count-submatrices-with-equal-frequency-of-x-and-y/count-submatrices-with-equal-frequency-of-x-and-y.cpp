class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> countx(n, 0);
        vector<int> county(n, 0);
        int ans = 0;
        for(int i=0;i<m;i++){
            int rowx = 0;
            int rowy = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j]=='X'){
                    rowx++;
                }
                if(grid[i][j]=='Y'){
                    rowy++;
                }
                countx[j] += rowx;
                county[j] += rowy;
                
                if(countx[j]!=0 && countx[j]==county[j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};