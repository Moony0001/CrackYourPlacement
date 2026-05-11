class Solution {
public:
    void digitize(int i, vector<int>& a){
        int temp = i;
        stack<int> st;
        while(temp>0){
            st.push(temp%10);
            temp/=10;
        }
        while(!st.empty()){
            a.push_back(st.top());
            st.pop();
        }

    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            digitize(nums[i], ans);
        }
        return ans;
    }
};