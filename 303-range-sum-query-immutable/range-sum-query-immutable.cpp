class NumArray {
private:
    vector<int> accu;
public:
    NumArray(vector<int>& nums) {
        accu.push_back(0);
        for(int i=0;i<nums.size();i++){
            accu.push_back(nums[i]+accu[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return (accu[right+1]-accu[left]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */