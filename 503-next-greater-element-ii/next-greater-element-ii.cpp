class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int i = 0;
        int n = nums.size();
        vector<int> ans(n, -1);

        while (i < 2 * n) {
            while (!st.empty() && nums[st.top()] < nums[i % n]) {
                ans[st.top()] = nums[i % n];
                st.pop();
            }
            if(i<n){
                st.push(i % n);
            }

            i++;
        }

        return ans;
    }
};