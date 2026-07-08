class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left_most_good_index = nums.size()-1;
        for(int i = nums.size()-2; i >= 0; i--){
            if(i+nums[i] >= left_most_good_index){
                left_most_good_index = i;
            }
        }
        return left_most_good_index == 0;
    }
};