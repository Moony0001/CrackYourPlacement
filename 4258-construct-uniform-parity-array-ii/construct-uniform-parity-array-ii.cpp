class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> even;
        vector<int> odd;
        for(int i : nums1){
            if(i&1){
                odd.push_back(i);
            }else{
                even.push_back(i);
            }
        }
        if(even.size()==0 || odd.size()==0){
            return true;
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        for(int i=0;i<even.size();i++){
            int s = even[i];
            auto it = lower_bound(odd.begin(), odd.end(), s);
            if(it==odd.begin()){
                return false;
            }
        }
        return true;
    }
};