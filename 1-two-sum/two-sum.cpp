class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
        int first = 0;
        int second = 0;
        for(int i=0;i<n;i++){
            int temp = target-nums[i];
            if(mp.count(temp) && mp[temp]!=i){
                first = i;
                second = mp[temp];
                break;
            }
        }
        return {first, second};
    }
};