class Solution {
public:
    int largestrect(vector<int> nums){
        int n = nums.size();
        stack<int> st;
        long long ans = INT_MIN;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.top()]>nums[i])){
                int curr = st.top();
                st.pop();
                int right = i;
                int left = st.empty() ? -1 : st.top();
                long long cnt = right-left-1;
                long long cont = cnt*nums[curr];
                ans = max(ans, cont);
            }
            st.push(i);
        }
        return ans;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> h(m,0);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    h[j] += 1;
                }else{
                    h[j] = 0;
                }
            }
            ans = max(largestrect(h), ans);
        }
        return ans;
    }
};