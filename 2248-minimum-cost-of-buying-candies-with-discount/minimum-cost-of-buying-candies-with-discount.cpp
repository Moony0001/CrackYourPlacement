class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int i = n-1;
        int j = n-2;
        int ans = 0;
        while(i>=0 && j>=0){
            ans += (cost[i]+cost[j]);
            i-=3; j-=3;
        }

        if(i>=0){
            ans += cost[i];
            i-=3;
        }
        return ans;
    }
};