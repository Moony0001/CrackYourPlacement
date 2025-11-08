class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                continue;
            }else{
                curr++;
                nums[curr] = nums[i+1];
            }
        }
        return curr+1;
    }
};