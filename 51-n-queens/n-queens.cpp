class Solution {
public:

    bool isvalid(vector<string>& can, int row, int col){
        //check the top direction
        for(int i=row;i>=0;i--){
            if(can[i][col]=='Q') return false;
        }
        //check the upper-left diagonal
        for(int i=row, j=col; i>=0 && j>=0;i--, j--){
            if(can[i][j]=='Q') return false;
        }
        //check the upper-right diagonal
        for(int i=row, j=col; i>=0 && j<can.size();i--, j++){
            if(can[i][j]=='Q') return false;
        }

        return true;
    }

    void addq(vector<vector<string>>& ans, vector<string>& can, int row){
        if(row==can.size()){
            ans.push_back(can);
            return;
        }

        for(int i=0;i<can.size();i++){
            if(isvalid(can, row, i)){
                can[row][i]='Q';
                addq(ans, can, row+1);
                can[row][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> can (n, string (n, '.'));
        addq(ans, can, 0);
        return ans;
    }
};