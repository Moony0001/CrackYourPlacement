class Solution {
public:
    bool check(vector<vector<char>>& board, string& s, int i, int j, int ind) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (s[ind] != board[i][j])
            return false;
        if (ind == s.size() - 1 && s[ind] == board[i][j])
            return true;
        board[i][j] = '*';

        int dir[5] = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            if (check(board, s, i + dir[k], j + dir[k + 1], ind + 1)) {
                return true;
            }
        }
        board[i][j] = s[ind];
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        // Pruning to check whether board even has enough letters
        vector<int> freq(128, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                freq[board[i][j]]++;
            }
        }

        for (char c : word) {
            if (--freq[c] < 0)
                return false;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};