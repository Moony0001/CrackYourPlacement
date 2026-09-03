class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> even;
        vector<int> odd;
        int minodd = INT_MAX;
        for(int i : nums1){
            if(i&1){
                odd.push_back(i);
                minodd = min(minodd, i);
            }else{
                even.push_back(i);
            }
        }
        if(even.size()==0 || odd.size()==0){
            return true;
        }

        for(int i=0;i<even.size();i++){
            if(even[i] < minodd) return false;
        }
        return true;
    }
};