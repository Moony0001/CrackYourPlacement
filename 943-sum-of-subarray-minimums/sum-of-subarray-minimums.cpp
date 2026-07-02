class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left (n,-1);
        vector<int> right (n,n);

        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        stack<int> st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && arr[st1.top()]>=arr[i]){
                left[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
        long long sum = 0;
        for(int i=0;i<n;i++){
            long long leftc = (i-left[i]);
            long long rightc = (right[i]-i);
            long long cnt = (leftc*rightc);
            long long cont = (cnt*arr[i])%1000000007;
            sum = (sum + cont)%1000000007;
        }
        return sum;
    }
};