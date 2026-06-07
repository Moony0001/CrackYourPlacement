class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m-1;

        bool ans = false;
        while(row<n && col>=0){
            if(matrix[row][col]==target){
                ans = true;
                break;
            }else if(matrix[row][col]>target){
                col--;
            }else{
                row++;
            }
        }
        return ans;
    }
};