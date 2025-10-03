class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int l;

public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i<k){
                pq.push(nums[i]);
            }else if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        l = k;
    }

    int add(int val) {
        if(pq.size()<l){
            pq.push(val);
        }else if(pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */