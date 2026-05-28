class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int i=0; int j=i+1;
        while(i<n && j<n){
            bool flag = false;
            if(max(intervals[i][0], intervals[j][0])<=min(intervals[i][1], intervals[j][1])){
                flag = true;
                intervals[j][0] = min(intervals[i][0], intervals[j][0]);
                intervals[j][1] = max(intervals[i][1], intervals[j][1]);
                // i++;
                // j++;
            }

            if(!flag){
                ans.push_back(intervals[i]);
                // i++;
                // j++;
            }
            i++;
            j++;
        }
        ans.push_back(intervals[i]);
        return ans;
    }
};