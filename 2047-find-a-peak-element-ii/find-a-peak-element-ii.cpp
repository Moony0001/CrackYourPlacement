class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0;
        int right = m - 1;
        vector<int> ans = {-1, -1};
        while (left <= right) {
            int mid = left + (right - left) / 2;

            int ind = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[ind][mid]) {
                    ind = i;
                }
            }

            int leftn = mid - 1 >= 0 ? mat[ind][mid - 1] : -1;
            int rightn = mid + 1 < m ? mat[ind][mid + 1] : -1;
            int curr = mat[ind][mid];

            if (curr > leftn && curr > rightn) {
                ans = {ind, mid};
                break;
            } else if (curr < leftn) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};