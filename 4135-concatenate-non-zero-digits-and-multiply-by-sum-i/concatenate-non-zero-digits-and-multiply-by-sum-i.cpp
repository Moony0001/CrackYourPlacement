class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        long long sum = 0;
        stack<int> st;
        while(n>0){
            int temp = n%10;
            if(temp>0){
                st.push(temp);
                sum += temp;
            }
            n /=10;
        }
        while(!st.empty()){
            ans = ans*10 + st.top();
            st.pop();
        }
        return ans*sum;
    }
};