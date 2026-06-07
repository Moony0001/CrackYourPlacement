class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool ans = false;
        for(int i=0;i<n;i++){
            int low = 0;
            int high = m-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(matrix[i][mid]==target){
                    ans = true;
                    break;
                }else if(matrix[i][mid]>target){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            if(ans){
                break;
            }
        }
        return ans;
    }
};