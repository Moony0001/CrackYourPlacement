class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>> st;
        int i = 0;
        int n = nums.size();
        vector<int> ans (n,-1);

        while(i<2*n){
            if(st.empty()){
                st.push({nums[i%n], (i%n)});
            }else{
                while(!st.empty() && st.top().first<nums[i%n]){
                    ans[st.top().second] = nums[i%n];
                    st.pop();
                }
                st.push({nums[i%n], (i%n)});
            }   
            i++;
        }

        return ans;
    }
};