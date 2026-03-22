class Solution {
public:
    int minab(vector<vector<int>>& grid, int k, int a, int b){
        vector<int> temp;
        for(int i=a;i<a+k;i++){
            for(int j=b;j<b+k;j++){
                temp.push_back(grid[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        int ans = INT_MAX;
        if(temp.size()==1 || temp[0]==temp[temp.size()-1]){
            ans = 0;
        }
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i]!=temp[i+1]){
                ans = min(ans, abs(temp[i]-temp[i+1]));
            }
        }
        return ans;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));
        for(int i=0;i<m-k+1;i++){
            for(int j=0;j<n-k+1;j++){
                ans[i][j] = minab(grid, k, i, j);
            }
        }
        return ans;
    }
};