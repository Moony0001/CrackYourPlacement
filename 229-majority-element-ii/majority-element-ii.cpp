class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int lim = n/3;
        int candidate1 = nums[0];
        int cnt1 = 1;
        int candidate2 = 1e9+1;
        int cnt2 = 0;
        for(int i=1;i<n;i++){
            if(nums[i]!=candidate2 && !cnt1){
                candidate1 = nums[i];
                cnt1++;
            }else if(nums[i]!=candidate1 && !cnt2){
                candidate2 = nums[i];
                cnt2++;
            }else if(nums[i]==candidate1){
                cnt1++;
            }else if(nums[i]==candidate2){
                cnt2++;
            }else if(nums[i]!=candidate1 && nums[i]!=candidate2){
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==candidate1){
                cnt1++;
            }
            if(nums[i]==candidate2){
                cnt2++;
            }
        }

        if(cnt1>(n/3)){
            ans.push_back(candidate1);
        }
        if(cnt2>(n/3)){
            ans.push_back(candidate2);
        }
        return ans;
    }
};