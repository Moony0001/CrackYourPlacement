class StockSpanner {
public:
    vector<int> v;
    stack<int> st;
    int cnt;

    StockSpanner() {
        cnt = 0;
    }
    
    int next(int price) {
        int ans = 1;
        while(!st.empty() && v[st.top()]<=price){
            st.pop();
        }
        int left = st.empty() ? -1 : st.top();
        ans = max(ans, cnt-left);
        st.push(cnt);
        v.push_back(price);
        cnt++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */