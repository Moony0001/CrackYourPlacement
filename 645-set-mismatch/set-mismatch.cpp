class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size();
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        unordered_set<int> st(v.begin(), v.end());
        for(int i=0;i<n;i++){
            if(st.count(nums[i])){
                st.erase(nums[i]);
            }else{
                ans[0] = nums[i];
            }
        }
        ans[1] = *st.begin();
        return ans;
    }
};