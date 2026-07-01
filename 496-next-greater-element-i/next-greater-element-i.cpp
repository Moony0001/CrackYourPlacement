class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;

        for(int i=0;i<nums2.size();i++){
            if(st.empty()){
                st.push(nums2[i]);
                continue;
            }else{
                while(!st.empty() && st.top()<nums2[i]){
                    mp[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }

        vector<int> ans;
        for(int i : nums1){
            if(mp.count(i)){
                ans.push_back(mp[i]);

            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};