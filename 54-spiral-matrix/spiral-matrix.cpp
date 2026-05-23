class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int startr = 0;
        int startc = 0;
        int endr = matrix.size()-1;
        int endc = matrix[0].size()-1;

        while(startr<=endr && startc<=endc){
            for(int i=startc;i<=endc;i++){
                ans.push_back(matrix[startr][i]);
            }
            for(int i=startr+1;i<=endr;i++){
                ans.push_back(matrix[i][endc]);
            }
            if(startr<endr){
                for(int i=endc-1;i>startc;i--){
                    ans.push_back(matrix[endr][i]);
                }
            }
            if(startc<endc){
                for(int i=endr;i>startr;i--){
                    ans.push_back(matrix[i][startc]);
                }
            }
            
            startr++;
            startc++;
            endr--;
            endc--;
        }
        return ans;
    }
};