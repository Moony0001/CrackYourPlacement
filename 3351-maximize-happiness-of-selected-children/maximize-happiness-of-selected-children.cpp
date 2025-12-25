class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());
        long long minus = 0;
        long long ans = 0;
        for(int i=n-1;i>=n-k;i--){
            ans += (long long)((happiness[i]-minus>=0)?(happiness[i]-minus):0);
            minus++;
        }
        return ans;

    }
};