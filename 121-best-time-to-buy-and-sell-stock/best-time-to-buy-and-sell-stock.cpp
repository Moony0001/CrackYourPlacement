class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        for(int i=0; i<n-1;i++){
            prices[i] = prices[i+1]-prices[i];
        }
        prices[n-1] = 0;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            sum+=prices[i];
            if(sum<0){
                sum = 0;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};