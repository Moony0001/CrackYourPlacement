class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        long long ans = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>heights[i])){
                int right = i;
                int curr = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                long long cnt = right-left-1;
                long long cont = cnt*heights[curr];
                ans = max(ans, cont);
            }
            st.push(i);
        }
        return ans;
    }
};