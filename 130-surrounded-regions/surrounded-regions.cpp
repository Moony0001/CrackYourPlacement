class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i, 0});
                board[i][0] = 'N';
            }
            if(board[i][m-1]=='O'){
                q.push({i, m-1});
                board[i][m-1] = 'N';
            }
        }

        for(int i=1;i<m-1;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                board[0][i] = 'N';
            }
            if(board[n-1][i]=='O'){
                q.push({n-1, i});
                board[n-1][i]='N';
            }
        }

        vector<int> dx = {0, 1, -1, 0};
        vector<int> dy = {-1, 0, 0, 1};

        while(!q.empty()){
            pair<int, int> front = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int tempx = front.first+dx[i];
                int tempy = front.second+dy[i];

                if(tempx>=0 && tempx<n && tempy>=0 && tempy<m){
                    if(board[tempx][tempy]=='O'){
                        board[tempx][tempy]='N';
                        q.push({tempx, tempy});
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }else if(board[i][j]=='N'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};