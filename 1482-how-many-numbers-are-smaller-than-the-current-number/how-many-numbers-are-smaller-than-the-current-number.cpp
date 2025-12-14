class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        map<int, int> mp;
        int n = nums.size();
        sort(temp.begin(), temp.end());
        int pos = 0;
        int carry = 0;
        for(int i=0;i<n;i++){
            if(i>0){
                if(temp[i-1]!=temp[i]){
                    pos++;
                    pos+= carry;
                    carry = 0;
                }else{
                    carry++;
                }
            }
            mp[temp[i]] = pos;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = mp[nums[i]];
        }
        return ans;
    }
};