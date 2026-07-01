class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxleft = height[left];
        int maxright = height[right];
        int ans = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (maxleft <= height[left]) {
                    maxleft = height[left];
                } else {
                    ans += maxleft - height[left];
                }
                left++;
            } else {
                if (height[right] >= maxright) {
                    maxright = height[right];
                }else{
                    ans += maxright-height[right];
                
                }
                right--;
            }
        }
        return ans;
    }
};