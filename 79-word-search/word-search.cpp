class Solution {
public:

    bool check(vector<vector<char>>& board, vector<vector<int>>& vis, string s, int i, int j, int ind){
        if(s[ind]!=board[i][j]) return false;
        if(ind==s.size()-1 && s[ind]==board[i][j]) return true;
        vis[i][j] = 1;
        // bool a = false, b = false, c = false, d = false;
        if(i+1<board.size() && !vis[i+1][j]){
            if(check(board, vis, s, i+1, j, ind+1)){
                return true;
            }
        }
        if(i-1>=0 && !vis[i-1][j]){
            if(check(board, vis, s, i-1, j, ind+1)){
                return true;
            }
        }
        if(j+1<board[0].size() && !vis[i][j+1]){
            if(check(board, vis, s, i, j+1, ind+1)){
                return true;
            }
        }
        if(j-1>=0 && !vis[i][j-1]){
            if(check(board, vis, s, i, j-1, ind+1)){
                return true;
            }
        }
        vis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(board, vis, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};