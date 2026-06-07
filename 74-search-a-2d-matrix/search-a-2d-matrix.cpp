class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int right = n;
        while(left<right){
            int mid = left + (right-left)/2;

            if(matrix[mid][0]>=target){
                right = mid;
            }else{
                left = mid+1;
            }
        }

        int row = left<n ? (matrix[left][0]==target ? left : (left>0 ? left-1 : left)) : left-1;

        left = 0;
        right = m-1;

        bool ans = false;
        while(left<=right){
            int mid = left + (right-left)/2;

            if(matrix[row][mid]==target){
                ans = true;
                break;
            }else if(matrix[row][mid]>target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};