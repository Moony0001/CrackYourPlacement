class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool x1 = true, x2 = true, x3 = true, x4 = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j]){
                    x1 = false;
                    break;
                }
            }
            if(!x1){
                break;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(mat[j][i]!=target[i][n-1-j]){
                    x2 = false;
                    break;
                }
            }
            if(!x2){
                break;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]!=target[n-1-i][n-1-j]){
                    x3 = false;
                    break;
                }
            }
            if(!x3){
                break;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(mat[j][i]!=target[n-1-i][j]){
                    x4 = false;
                    break;
                }
            }
            if(!x4){
                break;
            }
        }

        return (x1 || x2 || x3 || x4);
    }
};