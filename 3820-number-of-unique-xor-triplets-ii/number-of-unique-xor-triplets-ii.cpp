class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> seen(2048, false);
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int temp = nums[i]^nums[j];
                seen[temp] = true;
            }
        }
        vector<bool> ans(2048, false);
        for(int i=0;i<2048;i++){
            if(seen[i]){
                for(int j=0;j<n;j++){
                    int temp = i^nums[j];
                    ans[temp]=true;
                }
            }
        }

        int cnt = 0;
        for(bool f : ans){
            if(f){
                cnt++;
            }
        }
        return cnt;
    }
};