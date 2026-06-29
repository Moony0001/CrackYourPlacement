class MinStack {
private: 
    stack<int> st;
    vector<int> minv;
    int mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int value) {
        st.push(value);
        int i = INT_MAX;
        if(minv.size()!=0){
            i = minv.back();
        }
        
        mini = min(i, value);
        minv.push_back(mini);
    }
    
    void pop() {
        st.pop();
        minv.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minv.back();
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