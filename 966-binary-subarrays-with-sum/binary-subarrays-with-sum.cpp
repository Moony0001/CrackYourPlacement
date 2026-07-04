class Solution {
public:
    int atmostk(vector<int>& nums, int k){
        if(k<0) return 0;
        int i = 0;
        int sum = 0;
        int cnt = 0;
        for(int j = 0;j<nums.size();j++){
            sum += nums[j];
            while(sum>k){
                sum-=nums[i];
                i++;
            }
            cnt += (j-i+1);
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostk(nums,goal)-atmostk(nums, goal-1);
    }
};