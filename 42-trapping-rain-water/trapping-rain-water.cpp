class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxleft (n,0);
        vector<int> maxright (n,0);
        maxleft[0] = height[0];
        maxright[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            maxleft[i] = max(maxleft[i-1], height[i]);
            maxright[n-i-1] = max(maxright[n-i], height[n-i-1]);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            ans += abs(min(maxleft[i],maxright[i])-height[i]);
        }
        return ans;
    }
};