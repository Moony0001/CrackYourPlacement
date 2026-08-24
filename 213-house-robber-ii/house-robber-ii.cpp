class Solution {
public:
    // bool flag;
    int solve(vector<int>& nums, int i, int limit, vector<int>& memo){
        if(i>limit) return 0;
        if(memo[i]!=-1){
            return memo[i];
        }
        int steal = nums[i] + solve(nums, (i+2), limit, memo);
        int skip = solve(nums, (i+1), limit, memo);

        return memo[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }
        vector<int> memo1(n+1, -1);
        vector<int> memo2(n+1, -1);

        
        return max(solve(nums, 0, n-2, memo1), solve(nums, 1, n-1, memo2));

    }
};