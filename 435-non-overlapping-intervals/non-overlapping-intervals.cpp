class Solution {
public:
    // Sort strictly by ascending End Time
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        int removals = 0;
        int current_end = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            // Overlap! We must remove this new interval
            if(intervals[i][0] < current_end){
                removals++;
            } else {
                // No overlap, this is our new safe boundary
                current_end = intervals[i][1];
            }
        }
        return removals;
    }
};