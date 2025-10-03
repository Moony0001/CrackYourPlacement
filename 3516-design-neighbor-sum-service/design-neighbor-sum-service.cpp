class NeighborSum {
private:
    vector<vector<int>> ans;

public:
    NeighborSum(vector<vector<int>>& grid) {
        ans = grid;
    }
    
    int adjacentSum(int value) {
        int n = ans.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==value){
                    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
                    for(auto d:dir){
                        int newx = i+d.first;
                        int newy = j+d.second;
                        if(newx>=0 && newx<n && newy>=0 && newy<n){
                            sum+=ans[newx][newy];
                        }
                    }
                    return sum;
                }
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int n = ans.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==value){
                    vector<pair<int,int>> dir = {{1,1},{-1,1},{1,-1},{-1,-1}};
                    for(auto d:dir){
                        int newx = i+d.first;
                        int newy = j+d.second;
                        if(newx>=0 && newx<n && newy>=0 && newy<n){
                            sum+=ans[newx][newy];
                        }
                    }
                    return sum;
                }
            }
        }
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */