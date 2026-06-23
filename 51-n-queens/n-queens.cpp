class Solution {
public:

    void addq(vector<vector<string>>& ans, vector<string>& can, int row, vector<bool>& col, vector<bool>& major, vector<bool>& minor){
        if(row==can.size()){
            ans.push_back(can);
            return;
        }

        for(int i=0;i<can.size();i++){
            if(col[i]==0 && major[row-i+can.size()-1]==0 && minor[row+i]==0){
                can[row][i]='Q';
                col[i]=1;
                major[row-i+can.size()-1]=1;
                minor[row+i]=1;
                addq(ans, can, row+1, col, major, minor);
                can[row][i]='.';
                col[i]=0;
                major[row-i+can.size()-1]=0;
                minor[row+i]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> can (n, string (n, '.'));
        vector<bool> col (n, false);
        vector<bool> major (2*n-1, false);
        vector<bool> minor (2*n-1, false);
        addq(ans, can, 0, col, major, minor);
        return ans;
    }
};