class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;
        long long sum = 0;

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]>arr[i])){
                int right = i;
                int curr = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int leftc = curr-left;
                int rightc = right-curr;
                long long cnt = leftc*rightc;
                long long cont = (cnt*arr[curr])%1000000007;
                sum = (sum+cont)%1000000007;
            }
            st.push(i);
        }
        
        return sum;
    }
};