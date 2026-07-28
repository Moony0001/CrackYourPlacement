class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX/2));

        //First Pass
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dp[i][j] = 0;
                }else{
                    int mini = INT_MAX/2;
                    if(i-1>=0){
                        mini = min(mini, dp[i-1][j]+1);
                    }
                    if(j-1>=0){
                        mini = min(mini, dp[i][j-1]+1);
                    }
                    dp[i][j] = mini;
                }
            }
        }

        //Second Pass
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mini = dp[i][j];
                if(i+1<n){
                    mini = min(mini, dp[i+1][j]+1);
                }
                if(j+1<m){
                    mini = min(mini, dp[i][j+1]+1);
                }
                dp[i][j] = mini;
            }
        }
        return dp;
    }
};