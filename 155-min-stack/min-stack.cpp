class MinStack {
private: 
    vector<long long> st;
    long long mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push_back(value);
        }else if(mini>value){
            st.push_back(2LL*value-mini);
            mini = value;
        }else{
            st.push_back(value);
        }
    }
    
    void pop() {
        long long val = st.back();
        st.pop_back();
        if(val<mini){
            mini = 2LL*mini-val;
        }
    }
    
    int top() {
        long long val = st.back();
        return (val<mini) ? mini : val;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */