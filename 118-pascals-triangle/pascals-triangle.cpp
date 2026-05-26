class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        pascal(numRows, ans);
        return ans;
    }

    void pascal(int k, vector<vector<int>>& ans){
        if(k==1){
            ans.push_back({1});
            return;
        }
        pascal(k-1,ans);
        vector<int> temp(k,0);
        temp[0]=1;
        temp[k-1]=1;
        vector<int> last = ans[ans.size()-1];
        for(int i=1;i<=k-2;i++){
            temp[i] = last[i-1]+last[i];
        }
        ans.push_back(temp);
        return;
    }
};