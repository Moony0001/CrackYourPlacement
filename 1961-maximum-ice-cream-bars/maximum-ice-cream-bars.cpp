class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int i =0;
        int ans =0;
        int n = costs.size();
        while(i<n && coins>0){
            if(costs[i]<=coins){
                coins-=costs[i];
                ans++;
            }else{
                break;
            }
            i++;
        }
        return ans;
    }
};