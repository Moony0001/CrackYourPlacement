class OrderedStream {
private:
    int ptr=0;
    vector<string> st;
public:
    OrderedStream(int n) {
        st.assign(n,"#");
    }
    
    vector<string> insert(int idKey, string value) {
        st[idKey-1]=value;
        vector<string> ans;
        while(ptr<st.size() && st[ptr]!="#"){
            ans.push_back(st[ptr]);
            ptr++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */