class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }

        int s = temp.size();
        k = k%s;
        if(k==0) return grid;
        int i = s-k;
        int x = 0;
        int y = 0;
        while(true){
            int replace = temp[i];
            grid[x][y] = replace;
            if(y==m-1){
                y = 0;
                x++;
            }else{
                y++;
            }
            i = (i+1)%s;
            if(i==s-k){
                break;
            }
        }

        return grid;
    }
};