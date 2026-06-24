class Solution {
public:

    bool build(vector<vector<char>>& board, vector<unordered_set<int>>& rows, vector<unordered_set<int>>& col, vector<unordered_set<int>>& box, int i, int j){
        // If j ever becomes 9 then that means that the right boundary for that row was crossed so we need to actually move on to the first column of the next row
        if(j==9) return build(board, rows, col, box, i+1, 0);
        //If i ever becomes 9 this means that we crossed the last (8,8) square and it became i==9 this means we put all the numbers in the board and hence we can return true.
        if(i==9) return true;

        if(board[i][j]!='.') return build(board, rows, col, box, i, j+1);

        for(int k=1;k<=9;k++){
            if(!rows[i].count(k) && !col[j].count(k) && !box[3*(i/3)+(j/3)].count(k)){
                
                board[i][j] = '0'+k;
                rows[i].insert(k);
                col[j].insert(k);
                box[3*(i/3)+(j/3)].insert(k);

                if(build(board, rows, col, box, i, j+1)){
                    return true;
                }
                    
                board[i][j] = '.';
                rows[i].erase(k);
                col[j].erase(k);
                box[3*(i/3)+(j/3)].erase(k);
                
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows (9);
        vector<unordered_set<int>> col (9);
        vector<unordered_set<int>> box (9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    rows[i].insert(board[i][j]-'0');
                    col[j].insert(board[i][j]-'0');
                    int indx = i/3;
                    int indy = j/3;
                    int ind = 3*indx+indy;
                    box[ind].insert(board[i][j]-'0');
                }
            }
        }

        build(board, rows, col, box, 0, 0);
    }
};