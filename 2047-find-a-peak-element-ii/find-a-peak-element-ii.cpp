class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int row = 0;
        int col = 0;
        while (row < n && col < m) {
            int maxi = mat[row][col];
            int tempr = row;
            int tempc = col;
            bool flag = false;
            if (row > 0 && row < n - 1 && col > 0 && col < m - 1) {
                if (mat[row - 1][col] > maxi) {
                    tempr = row - 1;
                    tempc = col;
                    maxi = mat[row - 1][col];
                    flag = true;
                }
                if (mat[row + 1][col] > maxi) {
                    tempr = row + 1;
                    tempc = col;
                    maxi = mat[row + 1][col];
                    flag = true;
                }
                if (mat[row][col - 1] > maxi) {
                    tempc = col - 1;
                    tempr = row;
                    maxi = mat[row][col - 1];
                    flag = true;
                }
                if (mat[row][col + 1] > maxi) {
                    tempc = col + 1;
                    tempr = row;
                    maxi = mat[row][col + 1];
                    flag = true;
                }
            } else if (row == 0) {
                if (mat[row + 1][col] > maxi) {
                    maxi = mat[row + 1][col];
                    tempr = row + 1;
                    tempc = col;
                    flag = true;
                }
                if (col != m - 1) {
                    if (mat[row][col + 1] > maxi) {
                        maxi = mat[row][col + 1];
                        tempc = col + 1;
                        tempr = row;
                        flag = true;
                    }
                }
                if (col != 0) {
                    if (mat[row][col - 1] > maxi) {
                        maxi = mat[row][col - 1];
                        tempc = col - 1;
                        tempr = row;
                        flag = true;
                    }
                }
            } else if (row == n - 1) {
                if (mat[row - 1][col] > maxi) {
                    maxi = mat[row - 1][col];
                    tempr = row - 1;
                    tempc = col;
                    flag = true;
                }
                if (col != m - 1) {
                    if (mat[row][col + 1] > maxi) {
                        maxi = mat[row][col + 1];
                        tempc = col + 1;
                        tempr = row;
                        flag = true;
                    }
                }
                if (col != 0) {
                    if (mat[row][col - 1] > maxi) {
                        maxi = mat[row][col - 1];
                        tempc = col - 1;
                        tempr = row;
                        flag = true;
                    }
                }
            } else if (col == 0) {
                if (mat[row][col + 1] > maxi) {
                    tempc = col + 1;
                    tempr = row;
                    maxi = mat[row][col + 1];
                    flag = true;
                }
                if (row != 0) {
                    if (mat[row - 1][col] > maxi) {
                        maxi = mat[row - 1][col];
                        tempr = row - 1;
                        tempc = col;
                        flag = true;
                    }
                }
                if (row != n - 1) {
                    if (mat[row + 1][col] > maxi) {
                        maxi = mat[row + 1][col];
                        tempr = row + 1;
                        tempc = col;
                        flag = true;
                    }
                }
            } else if (col == m - 1) {
                if (mat[row][col - 1] > maxi) {
                    tempc = col - 1;
                    tempr = row;
                    maxi = mat[row][col - 1];
                    flag = true;
                }
                if (row != 0) {
                    if (mat[row - 1][col] > maxi) {
                        maxi = mat[row - 1][col];
                        tempr = row - 1;
                        tempc = col;
                        flag = true;
                    }
                }
                if (row != n - 1) {
                    if (mat[row + 1][col] > maxi) {
                        maxi = mat[row + 1][col];
                        tempr = row + 1;
                        tempc = col;
                        flag = true;
                    }
                }
            }
            if (flag) {
                row = tempr;
                col = tempc;
            } else {
                break;
            }
        }
        return {row, col};
    }
};