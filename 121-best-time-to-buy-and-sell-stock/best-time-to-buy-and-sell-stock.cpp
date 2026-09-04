class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int ans = 0;
        for(int i : prices){
            mini = min(mini, i);
            ans = max(ans, i-mini);
        }
        return ans;
    }
};