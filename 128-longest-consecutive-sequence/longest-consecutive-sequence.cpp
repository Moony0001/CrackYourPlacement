class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        for(int s:st){
            if(!st.count(s-1)){
                int cnt = 0;
                int j = s;
                while(st.count(j)){
                    cnt++;
                    j++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};