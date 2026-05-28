class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left = j+1;
                int right = n-1;

                if(i>0 && nums[i]==nums[i-1]) continue;
                if(j>(i+1) && nums[j]==nums[j-1]) continue;
                if(target>0 && nums[i]>target) break;

                while(left<right){
                    if((long long)nums[i]+nums[j]+nums[left]+nums[right]==(long long)target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;
                        while(left<right && nums[left]==nums[left-1]){
                            left++;
                        }
                        while(left<right && nums[right]==nums[right+1]){
                            right--;
                        }
                    }else if((long long)nums[i]+nums[j]+nums[left]+nums[right]<target){
                        left++;
                        while(left<right && nums[left]==nums[left-1]){
                            left++;
                        }
                    }else{
                        right--;
                        while(left<right && nums[right]==nums[right+1]){
                            right--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};