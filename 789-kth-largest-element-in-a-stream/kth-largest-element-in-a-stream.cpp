class KthLargest {
private:
    multiset<int> sortedScores;
    int l;

public:
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) {
            sortedScores.insert(num);
        }
        l = k;
    }

    int add(int val) {
        sortedScores.insert(val);
        auto largest = sortedScores.rbegin();
        for(int i=0;i<l-1;i++){
            largest++;
        }
        return *largest;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */