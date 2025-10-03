class RecentCounter {
private:
    vector<int> counter;

public:
    RecentCounter() {
        counter = {};
    }
    
    int ping(int t) {
        counter.push_back(t);
        auto it = lower_bound(counter.begin(), counter.end(), t-3000);
        int dist = distance(counter.begin(), it);
        return counter.size()-dist;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */