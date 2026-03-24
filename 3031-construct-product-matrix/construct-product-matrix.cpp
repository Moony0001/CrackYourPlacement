class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int md = 12345;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> suf(n*m, 0);
        vector<int> pref(n*m, 0);
        int prev = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                suf[i*m+j] = ((prev%md)*(grid[i][j]%md))%md;
                prev = suf[i*m+j];
            }
        }
        prev = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                pref[i*m+j] = ((prev%md)*(grid[i][j]%md))%md;
                prev = pref[i*m+j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    ans[i][j] = pref[i*m+j+1]%md;
                }else if(i==n-1 && j==m-1){
                    ans[i][j] = suf[i*m+j-1]%md;
                }else{
                    ans[i][j] = ((pref[i*m+j+1]%md)*(suf[i*m+j-1]%md))%md;
                }
            }
        }
        return ans;
    }
};