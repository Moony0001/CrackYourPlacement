class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans;
        int cnt = 0;
        vector<int> st;
        for(int i : nums){
            if(i<pivot){
                ans.push_back(i);
            }else if(i>pivot){
                st.push_back(i);
            }else{
                cnt++;
            }
        }

        while(cnt>0){
            ans.push_back(pivot);
            cnt--;
        }

        for(int i : st){
            ans.push_back(i);
        }
        
        return ans;
    }
};