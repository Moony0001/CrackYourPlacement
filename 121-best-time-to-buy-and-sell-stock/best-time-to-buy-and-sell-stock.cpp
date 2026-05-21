class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxi = 0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<mini){
                mini = prices[i];
            }
            if(prices[i]>mini){
                maxi = max(maxi, prices[i]-mini);
            }
        }
        return maxi;
    }
};