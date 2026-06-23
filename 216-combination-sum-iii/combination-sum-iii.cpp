class Solution {
public:

    void subsum(vector<vector<int>>& ans, vector<int>& can, int i, int s, int sum){
        if(sum==0 && s==0){
            ans.push_back(can);
            return;
        }
        if(s==0 || sum<0 || i>9) return;
        can.push_back(i);
        subsum(ans, can, i+1, s-1, sum-i);
        can.pop_back();
        subsum(ans, can, i+1, s, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> can; 
        subsum(ans, can, 1, k, n);
        return ans;
    }
};