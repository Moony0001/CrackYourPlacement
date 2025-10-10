class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxi = INT_MIN;
        for(int i=n-k;i<n;i++){
            int sum = 0;
            for(int j=i;j>=0;j-=k){
                sum+=energy[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};