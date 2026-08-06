class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<plantTime.size();i++){
            pq.push({growTime[i], plantTime[i]});
        }
        int ans = 0;
        int day = 0;

        while(!pq.empty()){
            int g = pq.top().first;
            int p = pq.top().second;
            pq.pop();
            day += p;
            ans = max(ans, day+g);
        }
        return ans;
    }
};