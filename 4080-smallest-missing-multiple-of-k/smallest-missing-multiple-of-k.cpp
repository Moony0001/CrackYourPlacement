class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(make_move_iterator(nums.begin()), make_move_iterator(nums.end()));

        int i = 1;
        while(st.count(k*i)){
            i++;
        }
        return k*i;
    }
};