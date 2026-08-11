class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]+1){
                ans += nums[i];
            }else{
                break;
            }
        }

        sort(nums.begin(), nums.end());
        auto it = lower_bound(nums.begin(), nums.end(), ans);
        int ind = it - nums.begin();
        if(it != nums.end()){
            if(*it == ans){
                while(ind < n && ans==nums[ind]){
                    while(ind<n && ans==nums[ind]){
                        ind++;
                    }
                    ans++;
                }
                return ans;
            }
        }
        return ans;
    }
};