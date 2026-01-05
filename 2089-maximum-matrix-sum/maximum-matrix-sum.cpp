class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        vector<int> minu;
        vector<int> plus;
        int n = matrix.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    minu.push_back(matrix[i][j]);
                }else{
                    ans+=matrix[i][j];
                    plus.push_back(matrix[i][j]);
                }
            }
        }

        sort(minu.begin(), minu.end());
        int m = minu.size();
        if(m&1){
            
            if(plus.size()>0){
                sort(plus.begin(), plus.end());
                int x = plus[0];
                int y = -1*minu[m-1];
                for(int i=0;i<m-1;i++){
                    ans += (-1*minu[i]);
                }
                if(x<y){
                    ans-=x;
                    ans+=y;
                    ans-=x;
                }else{
                    ans-=y;
                }
            }else{
                for(int i=0;i<m-1;i++){
                    ans += (-1*minu[i]);
                }
                ans+=minu[m-1];
            }
            
            
        }else{
            for(int i=0;i<m;i++){
                ans += (-1*minu[i]);
            }
        }
        return ans;

    }
};