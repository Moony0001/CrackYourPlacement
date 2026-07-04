class Solution {
public:
    int atmostk(vector<int>& nums, int k){
        int n = nums.size();
        int i=0;
        int cnt = 0;
        int sum = 0;
        for(int j=0;j<n;j++){
            if(nums[j]&1){
                cnt++;
            }
            while(cnt>k){
                if(nums[i]&1){
                    cnt--;
                }
                i++;
            }
            sum+=(j-i+1);
        }

        return sum;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return (atmostk(nums, k)-atmostk(nums,k-1));
    }
};