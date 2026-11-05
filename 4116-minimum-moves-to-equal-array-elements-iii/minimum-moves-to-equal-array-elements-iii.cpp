class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int t:nums){
            maxi = max(maxi, t);
        }
        int ans = 0;
        for(int t:nums){
            ans += (maxi-t);
        }
        return ans;
    }
};