class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(st.count(nums[i])){
                ans.push_back(nums[i]);
            }else{
                st.insert(nums[i]);
            }
        }
        return ans;
    }
};