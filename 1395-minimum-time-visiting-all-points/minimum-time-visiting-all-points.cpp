class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        int currx = points[0][0];
        int curry = points[0][1];
        for(int i=1;i<n;i++){
            int nextx = points[i][0];
            int nexty = points[i][1];
            int diffx = abs(nextx-currx);
            int diffy = abs(nexty-curry);

            ans += min(diffx, diffy);
            ans += abs(diffx-diffy);
            currx = nextx;
            curry = nexty;
        }
        return ans;
    }
};