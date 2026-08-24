class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        int a = 0;
        int b = 0;
        int steal = b;

        for(int i=start+1;i<=end+1;i++){
            steal = max(nums[i-1]+a, b);
            a = b;
            b = steal;
        }

        return steal;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    }
};