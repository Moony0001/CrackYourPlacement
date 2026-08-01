class Solution {
public:
    bool player(vector<int>& nums, int i, int j, int x, int sum1, int sum2) {
        if (i > j) {
            if (sum1 >= sum2)
                return true;
            else
                return false;
        }
        if (x == 1) {
            if (player(nums, i + 1, j, 2, sum1 + nums[i], sum2) ||
                player(nums, i, j - 1, 2, sum1 + nums[j], sum2)) {
                return true;
            }
        } else if (x == 2) {
            if (player(nums, i + 1, j, 1, sum1, sum2 + nums[i]) &&
                player(nums, i, j - 1, 1, sum1, sum2 + nums[j])) {
                return true;
            }
        }
        return false;
    }

    bool predictTheWinner(vector<int>& nums) {
        return player(nums, 0, nums.size()-1, 1, 0, 0);
    }
};