class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=y; i<(y+k); i++){
            int a = x;
            int b = x+k-1;
            while(a<b){
                int temp = grid[a][i];
                grid[a][i] = grid[b][i];
                grid[b][i] = temp;
                a++; b--;
            }
        }
        return grid;
    }
};