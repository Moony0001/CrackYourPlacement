class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int temp = n-k;
        int tsum = 0;
        for(int i : cardPoints){
            sum+=i;
            if(temp>0){
                tsum+=i;
                temp--;
            }
        }
        if(k==n) return sum;
        int i=0, j=n-k-1;
        int ans = sum-tsum;

        while(j<n-1){
            tsum-=cardPoints[i];
            i++;
            j++;
            tsum+=cardPoints[j];
            ans = max(ans,sum-tsum);
        }
        return ans;
    }
};