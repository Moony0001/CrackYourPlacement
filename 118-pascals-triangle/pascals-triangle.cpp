class Solution {
public:
    vector<int> rowbuilder(int n, vector<vector<int>>& ans){
        if(n==0) return {1};
        if(n==1) return {1, 1};

        vector<int> temp = ans[n-1];
        vector<int> res;
        res.push_back(1);
        for(int i=0;i<temp.size()-1;i++){
            res.push_back(temp[i]+temp[i+1]);
        }
        res.push_back(1);
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(rowbuilder(i, ans));
        }
        return ans;
    }
};