class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int n = intervals.size();
        vector<bool> in(n, false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(intervals[i][1]<=intervals[j][0]){
                    break;
                }
                if(!in[j]){
                    if((intervals[i][0]==min(intervals[i][0], intervals[j][0])) && intervals[i][1]==max(intervals[i][1], intervals[j][1])){
                        in[j] = true;
                    }
                }
            }
        }

        int ans = 0;
        for(bool b : in){
            if(!b) ans++;
        }
        return ans;
    }
};