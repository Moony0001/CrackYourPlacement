class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        for(int i : nums){
            auto it = lower_bound(arr.begin(), arr.end(), i);
            if(it!=arr.end()){
                *it = i;
            }else{
                arr.push_back(i);
            }
        }
        return arr.size();
    }
};