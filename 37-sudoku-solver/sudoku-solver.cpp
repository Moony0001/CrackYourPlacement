class Solution {
public:

    bool build(vector<vector<char>>& board, int (&rows) [9], int (&col) [9], int (&box) [9], int i, int j){
        // If j ever becomes 9 then that means that the right boundary for that row was crossed so we need to actually move on to the first column of the next row
        if(j==9) return build(board, rows, col, box, i+1, 0);
        //If i ever becomes 9 this means that we crossed the last (8,8) square and it became i==9 this means we put all the numbers in the board and hence we can return true.
        if(i==9) return true;

        if(board[i][j]!='.') return build(board, rows, col, box, i, j+1);

        for(int k=1;k<=9;k++){
            int mask = 1<<k;
            if(!(rows[i] & mask) && !(col[j] & mask) && !(box[3*(i/3)+(j/3)] & mask)){

                board[i][j] = '0'+k;
                rows[i]|= 1<<k;
                col[j]|= 1<<k;
                box[3*(i/3)+(j/3)]|= 1<<k;

                if(build(board, rows, col, box, i, j+1)){
                    return true;
                }
                    
                board[i][j] = '.';
                rows[i]^= mask;
                col[j]^= mask;
                box[3*(i/3)+(j/3)]^= mask;
                
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int col[9] = {0};
        int box[9] = {0};

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int x = board[i][j]-'0';
                    rows[i]|= 1<<x;
                    col[j]|= 1<<x;
                    box[3*(i/3)+(j/3)]|= 1<<x;
                }
            }
        }

        build(board, rows, col, box, 0, 0);
    }
};